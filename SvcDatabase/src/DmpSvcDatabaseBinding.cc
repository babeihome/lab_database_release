#include <boost/python.hpp>
#include "DmpSvcDatabase.h"

BOOST_PYTHON_MODULE(libDmpSvcDatabase){
  using namespace boost::python;

  class_<DmpSvcDatabase,boost::noncopyable,bases<DmpVSvc> >("DmpSvcDatabase",init<>());
}
