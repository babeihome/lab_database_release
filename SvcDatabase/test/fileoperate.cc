#include <string>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

char * strcpy(char * strDest,const char * strSrc)
{
	if ((NULL==strDest) || (NULL==strSrc)) //[1]
		cout<< "Invalid argument(s)"; //[2]
	char * strDestCopy = strDest; //[3]
	while ((*strDest++=*strSrc++)!='\0'); //[4]
	return strDestCopy;
}

int main()
{
	map<string,string> map1;
	map1["abc"] = "cba";
	map<string, string>::iterator map_iter = map1.begin();
	for(map_iter; map_iter != map1.end(); map_iter ++){
		cout << map_iter->first << endl;
	}
	return 1;

}

