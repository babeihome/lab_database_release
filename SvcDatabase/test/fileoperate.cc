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
		cout<< "file is not existed";
	}

	string line;
	char one_line[20];

	while (!infile.eof())
	{
		infile >> one_line;
		cout << one_line << endl;
		strcpy(one_line, "");
	}
	cout << "end" <<endl;
	infile.close();
	return 1;
}

