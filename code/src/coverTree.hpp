#ifndef _COVERTREE_
#define _COVERTREE_

#include <vector>

std::vector<std::string> explode(std::string str, char separator);

class CoverTree
{
private:
	int m_vertices;
	std::vector<std::vector<int>> m_edges;
	int m_root;

public:
	CoverTree(std::string SATstr);
	
	
};

#endif