__author__ = 'beibeihome'
import config
import friendly_api
import MySQLdb

def import_data():

    PATH = '/data/beamTest/2nd_2014_10/Calibration/DAMPE/Pedestal/PedestalPar'
    print "P: PATH is default setting\n"
    fp = open(PATH,"r")
    # file kind judgement
    file_type = 'EXPERIMENT'

    para_list = {}
    print "P: data parsing"
    if file_type == 'EXPERIMENT':
        # This data file has a constraint form. First line is the name of experiment , second line is start time, and third
        # line is end time.
        E_name = fp.readline().rstrip('\n')
        para_list['E_time0'] = fp.readline().rstrip('\n')
        para_list['E_time1'] = fp.readline().rstrip('\n')
        para_list['data_package'] = fp.read()

    elif file_type == 'SET':
        # have not been finished
        pass
    else:
        print 'P: File is not in right form\n'

    conn = MySQLdb.connect(host=config.HOST, user=config.USER, passwd=config.PASSWD, db=config.DATABASE, port=config.PORT)
    print "connection has built"
    if file_type == 'EXPERIMENT':
        print "P: inserting data\n"
        friendly_api.InsertData(conn, 'exp_data', para_list)
        print "P: data inserted\n"

        # auto update time_index
        print "P: time_index updating\n"
        time_index = {}
        order = 'SELECT S_time FROM set_data WHERE S_time <= ' + para_list['E_time0'] + ' ORDER BY S_time DESC LIMIT 1'
        cur = conn.cursor()
        cur.execute(order)
        result = cur.fetchone()
        time_index['S_time'] = str(result[0])
        time_index['E_time0'] = para_list['E_time0']
        time_index['E_name'] = E_name
        friendly_api.InsertData(conn, 'time_index', time_index)
        print "P: time_index updated\n"
    print "P: done\n"


def acquire_data(time):
    # time is in ms form
    conn = MySQLdb.connect(host=config.HOST, user=config.USER, passwd=config.PASSWD, db=config.DATABASE, port=config.PORT)
    print "P: connection has built"
    order = 'SELECT * FROM exp_data where E_time0 <= ' + str(time) + 'order by E_time0 DESC LIMIT 1'
    cur = conn.cursor()
    cur.execute(order)
    result = cur.fetchone()
    print "P: result has been read out"
    #print "P: type of result :" + str(type(result))
    #print "P: " + str(result)
    print "P: result type: " + str(type(result[4]))
    return result[4]
