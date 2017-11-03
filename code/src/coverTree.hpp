#ifndef _COVERTREE_
#define _COVERTREE_

#include <vector>
#include <iostream>

std::vector<std::string> explode(std::string str, char separator);

class CoverTree
{
private:
	int m_vertice;
	std::vector<CoverTree*> m_sons;

public:
	CoverTree(std::string SATstr);
	CoverTree(int vertice, std::vector<int> v, int k);
	~CoverTree();
	std::string toString();
	void addSon(int vertice, std::vector<int> v, int k);
	std::vector<CoverTree*> getSons();

	int getVertice();
	
	
};

std::ostream & operator<<(std::ostream & ofs, CoverTree const & cvt);

#endif