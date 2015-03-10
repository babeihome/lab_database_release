#include "DmpSvcDatabase.h"
#include <iostream>
#include <Python.h>

//-------------------------------------------------------------------
DmpSvcDatabase::DmpSvcDatabase()
 :DmpVSvc("DmpSvcDatabase")
{
	std::cout<<"\n\ninti..\n\n"<<std::endl;
	this->GetData("50000000");
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

std::fstream *DmpSvcDatabase::GetData(std::string t0)
{
	PyObject * result_py = NULL;
	char * data_bubble = NULL;
	std::fstream fs;

	Py_Initialize();

	if (!Py_IsInitialized()){
		DmpLogError << "Initialized fail" << DmpLogEndl;
		return 0;
	}

	PyRun_SimpleString("import sys");
	PyRun_SimpleString("import os.path");
	PyRun_SimpleString("sys.path.append('../share')");
	PyRun_SimpleString("sys.path.append('/usr/lib64/python2.6/site-packages/')");
	//Load python module
	//PyObject * pModule = PyImport_ImportModule("config");
	PyObject *pModule = PyImport_ImportModule("python_API");
	if (pModule == NULL){
		printf("pModule is NULL");
		Py_Finalize();
		getchar();
		return 0;
	}
	printf("C: operation level module imported\n");
	PyObject *pFunc = PyObject_GetAttrString(pModule, "acquire_data");
	if (pFunc == NULL){
		printf("pFunc is NULL");
		Py_Finalize();
		getchar();
		return 0;
	}
	printf("C: Function imported\n");
	PyObject *pArgv = Py_BuildValue("(s)", t0.c_str());
	printf("C: Is trying to call the import_data function\n");
	result_py = PyEval_CallObject(pFunc, pArgv);
	printf("C: function calling is over\n");
	PyArg_Parse(result_py, "s", &data_bubble);
	//Should make name of data package random
	std::cout << data_bubble;
	fs.open("./data_package.txt", std::ios::out);
	fs << data_bubble;
	fs.close();
	Py_Finalize();
	if (Py_IsInitialized())
	{
		DmpLogError << "Finalizing failed" << DmpLogEndl;
		return 0;
	}
	getchar();
	return 0;
}

