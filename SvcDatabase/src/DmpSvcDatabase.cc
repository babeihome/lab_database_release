#include "DmpSvcDatabase.h"
#include <iostream>

//-------------------------------------------------------------------
DmpSvcDatabase::DmpSvcDatabase()
 :DmpVSvc("DmpSvcDatabase")
{
	std::cout<<"\n\ninti..\n\n"<<std::endl;
	this->LinkMySQL();
}

//-------------------------------------------------------------------
DmpSvcDatabase::~DmpSvcDatabase(){
}

//-------------------------------------------------------------------
bool DmpSvcDatabase::Initialize(){
  return true;
}

//-------------------------------------------------------------------
bool DmpSvcDatabase::Finalize(){
  return true;
}

bool DmpSvcDatabase::LinkMySQL(std::string userName)
{
	std::cout<<"\tinput uname = "<<userName<<std::endl;
	return true;
}

