#include "coverTree.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int usage()
{
	cout << "./coverTree fileName" << endl;
	return -1;
}


int main(int argc, char *argv[])
{
	if(argc != 2)
		return usage();
	string fileName = argv[1], line;

	ifstream file(fileName);
	while(getline(file, line));

	CoverTree cvt(line);
	cout << cvt;

	return 0;
}