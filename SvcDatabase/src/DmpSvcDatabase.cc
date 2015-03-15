#include "DmpSvcDatabase.h"
#include <iostream>
#include <mysql/mysql.h>
#include <string>

#define HOST "dampe.ustc.edu.cn"
#define USER "cong"
#define PASSWD "cong"
#define DB "DmpSWDBTest"
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
	//std::cout<<"sssss"<<std::endl;
	//Test();
	mysql_init(&mysql);
	mysql_real_connect(&mysql, HOST, USER, PASSWD, DB, 3306, NULL, 0);
  	return true;
}

//-------------------------------------------------------------------
bool DmpSvcDatabase::Finalize(){
	//std::cout<<""<<std::endl;
	mysql_close(&mysql);
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
	std::fstream  fs;
	if (!mysql_query(&mysql, order.c_str())){
		std::cout<<"query error"<<std::endl;
		return 0;
	}
	result = mysql_store_result(&mysql);
	row = mysql_fetch_row(result);
	fs.open("./pedestal.txt",std::ios::out);
	fs << row[0];
	fs.close();
	return 0;
}
