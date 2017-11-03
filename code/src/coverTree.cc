#include "coverTree.hpp"
#include "all.h"
#include <string>
#include <cmath>


std::ostream & operator<<(std::ostream & ofs, CoverTree const & cvt)
{
	ofs << cvt.toString();
	return ofs;
}

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
	int k = (len-1 / count);

	for(int i = 0; i < len-1; i += k)
	{
		if(explodedSatInt[i] > 0)
		{
			m_vertice = i / k;
			explodedSatInt[i] -= explodedSatInt[i];
			break;
		}
	}
	for(int i = 0; i < len - 1; ++i)
	{
		if(!(explodedSatInt[i] > 0))
			continue;
		if(are_adjacent(getVertice(), explodedSatInt[i]) == 0)
			continue;
		addSon(floor(i/k), explodedSatInt);
	}
	
}

CoverTree::CoverTree(int vertice, std::vector<int> v) : m_vertice(vertice) 
{
	int size = v.size();
	for(int i = 0; i < size; ++i)
	{
		if(!(v[i] > 0))
			continue;
		if(are_adjacent(getVertice(), v[i]) == 0)
			continue;
		addSon(floor(i/k), v);
	}
}

CoverTree::~CoverTree()
{
	int l = m_sons.size();
	for(int i = 0; i < l; ++i)
		delete m_sons[i];
}

void CoverTree::addSon(int vertice)
{
	CoverTree *cvt = new CoverTree(vertice);
	m_sons.pushback(cvt);
}

std::string CoverTree::toString()
{
	std::string str = "";
	str += std::to_string(m_vertice);
	int l = m_sons.size();
	if(l > 0)
	{
		str += " - ( ";
		for(int i = 0; i < l; ++i)
		{
			str += m_sons[i]->toString();
		}
		str += " ) ";	
	}
	else
		str += " ";

	return str;
}

std::vector<CoverTree*> CovertTree::getSons() { return m_sons; }

int CovertTree::getVertice() { return m_vertice; }