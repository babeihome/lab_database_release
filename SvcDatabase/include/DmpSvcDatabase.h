#ifndef DmpSvcDatabase_H
#define DmpSvcDatabase_H

#include "DmpVSvc.h"
#include <fstream>
#include <vector>

class DmpSvcDatabase : public DmpVSvc{
/*
 *  DmpSvcDatabase
 *
 */
public:
  DmpSvcDatabase();
  ~DmpSvcDatabase();

  //void Set(const std::string &type,const std::string &value);
  // if you need to set some options for your algorithm at run time. Overload Set()
  bool Initialize();
  bool Finalize();

public:
  bool LinkMySQL(std::string userName="DAMPEDB");
  std::fstream *GetData(std::string t0);		// return a file which contains all parameter, refer to t0
  std::fstream *GetData(std::vector<std::string> conditions);

};

#endif
