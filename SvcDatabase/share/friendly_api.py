import MySQLdb


def InsertData(conn, TableName, dic):
    try:
        cur = conn.cursor()
        COLstr = ''
        ROWstr = ''

        for key in dic.keys():
            value_copy = '"' + dic[key] + '"'
            COLstr = ','.join([COLstr, key])
            ROWstr = ','.join([ROWstr, value_copy])
        COLstr = COLstr.lstrip(',')
        ROWstr = ROWstr.lstrip(',')
        order = 'INSERT INTO %s(%s) VALUES (%s)' % (TableName, COLstr, ROWstr)
        cur.execute(order)
        conn.commit()
        cur.close()
    except MySQLdb.Error, e:
        print order
        print "Mysql Error %d: %s" % (e.args[0], e.args[1])


def Select(conn, TableName, Row_name_list=[], where=[]):
    try:
        cur = conn.cursor()
        if Row_name_list == []:
            row_name = '*'
        else:
            row_name = str(Row_name_list).strip('[').strip(']').replace(' ','')
        order = 'SELECT ' + row_name + ' FROM ' + TableName
        cur.execute(order)
        # Data serialize 
        pass

        cur.close()
    except MySQL.Error, e:
        print order
        print "Mysql Error %d: %s" % (e.args[0], e.args[1])


def parameter_test(para):
    print "P: Type of parameter is " + str(type(para))
    print "P: Content: " + str(para)



