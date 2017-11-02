#include "coverTree.hpp"
#include "all.h"
#include <string>

std::vector<std::string> explode(std::string str, char separator)
{
	std::vector<std::string> result;
	std::string resultStr = "";
	int len = std::strlen(str);
	for(int i = 0; i < len; ++i)
	{
		if(str[i] == separator)
		{
			result.pushback(resultStr);
			resultStr = "";
		}
		else
			resultStr += str[i];
	}
	return result;
}

CoverTree::CoverTree(std::string SATstr)
{
	std::vector<std::string> explodedSat = explode(SATstr, ' ');
	std::vector<int> explodedSatInt;
	int len = explodedSat.size()-1;
	for(int i = 1; i < len; ++i)
		explodedSatInt.pushback(std::stol(explodedSat[i]));
	
	int count = 0; 
	for(int i = 0; i < len - 1; ++i)
	{
		if(explodedSatInt[i] > 0)
			++count;
	}

	m_vertices = count;
	m_edges.reserve(m_vertices);
	for(int i = 0; i < m_vertices; ++i)
	{
		for(int j = 0; j < m_vertices; ++j)
		{
			if(i == j)
				continue; 
			if(are_adjacent(i, j) == 1)
				m_edges[i].pushback(j);

		}
	}

	int k = (len-1 / count);
	for(int i = 0; i < len-1; i+= k)
	{
		if(explodedSatInt[i] > 0)
			m_root = i;
	}
}