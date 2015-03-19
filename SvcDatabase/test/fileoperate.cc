#include <string>
#include <fstream>
#include <iostream>

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
	ifstream infile("./test.txt");
	if (!infile)
	{
		cout<< "file is not existed"<<endl;
		return 0;
	}

	string line;
	char one_line[20];
	int n = 0; 
	while (!infile.eof()&& n<10)
	{
		infile.get(one_line,20, '\n');
		cout << one_line << endl;
		strcpy(one_line, "");
		n++;
		infile.get();
	}
	cout << "end" <<endl;
	infile.close();
	cout << "there is after .close()" << endl;
	return 1;
}

