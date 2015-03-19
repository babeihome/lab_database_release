#include "DmpSvcDatabase.h"
#include <iostream>
#include <mysql/mysql.h>
#include <string>

#define HOST "dampe.ustc.edu.cn"
#define USER "cong"
#define PASSWD "cong"
#define DB "DmpSWDBTest"

using namespace std;
//-------------------------------------------------------------------
DmpSvcDatabase::DmpSvcDatabase()
 :DmpVSvc("DmpSvcDatabase")
{
	std::cout<<"\n\n Database object created\n\n"<<std::endl;
}

//-------------------------------------------------------------------
DmpSvcDatabase::~DmpSvcDatabase(){
}

bool DmpSvcDatabase::Test()
{
	return true;
}

//-------------------------------------------------------------------
bool DmpSvcDatabase::Initialize(){
	mysql_init(&conn);
	if (&conn == NULL){
		printf("Error %u: %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 0;
	}

	if(!mysql_real_connect(&conn, HOST, USER, PASSWD, DB, 3306, NULL, 0))
	{
		printf("Error %u: %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 0;
	}
	GetData("500000");
  	return true;
}

//-------------------------------------------------------------------
bool DmpSvcDatabase::Finalize(){
	//std::cout<<""<<std::endl;
	mysql_close(&conn);
  return true;
}

bool DmpSvcDatabase::LinkMySQL(std::string userName)
{
	std::cout<<"\tinput uname = "<<userName<<std::endl;
	return true;
}

std::fstream *DmpSvcDatabase::GetData(std::string t0)
{
	std::string order = "SELECT * FROM time_index order by abs(" + t0 + " - E_time0) DESC LIMIT 1";
	MYSQL_RES * result = NULL;
	MYSQL_ROW row;
	int num_fields = 0;
	std::fstream  fs;
	if (mysql_query(&conn, order.c_str())){
		printf("Error %u: %s\n", mysql_errno(&conn), mysql_error(&conn));
		return 0;
	}
	result = mysql_store_result(&conn);
	num_fields = mysql_num_fields(result);
	row = mysql_fetch_row(result);
	// consider the condition of no result
	if(row){
		fs.open("./pedestal.txt",std::ios::out);
		std::cout << row[1] << std::endl;
		fs << row[0];
		fs.close();
	}
	return 0;
}

bool DmpSvcDatabase::Import_pedestal(bool test, std::string path)
{
	int para_num = 0;
	if (test == true){
		path = "/data/beamTest/2nd_2014_10/Calibration/DAMPE/Pedestal/PedestalPar";
		para_num = 3;
	}
	
	std::ifstream infile(path.c_str());
	char one_line[20];
	string one_line_str;
	vector<string> data_vector;
	if(!infile)
	{
		cout<< "Targeted file is not existed" << endl;
	}
	for(int para_count = 0; para_count < para_num; para_count++)
	{
		infile >> one_line;
		one_line_str = one_line;
		data_vector.push_back(one_line_str);
	}
	return 1;	
}	
