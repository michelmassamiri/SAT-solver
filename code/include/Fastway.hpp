/////////////////////////////////////////////////////////////
// FastWay 0.6
// Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
// Pavarino Arthur
/////////////////////////////////////////////////////////////

#ifndef FASTWAY_HPP_INCLUDED
#define FASTWAY_HPP_INCLUDED

#include <iostream>
#include <cstring>
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <vector>

#include "File.hpp"
#include "FileSize.hpp"
#include "UnitTest.hpp"

namespace fw
{

//bool fileListExists(std::string file);

//folder.cpp
bool createFolder(std::string folderName);

// Number.cpp
bool even(int number);

// Cast.cpp
std::string toString(char carac);
std::string toString(int number);
std::string toString(unsigned int number);
std::string toString(double number);
std::string toString(float number);
int toInt(std::string Content);

// string.cpp
std::string contentAfterCarac(std::string const& content, char carac);
std::vector<std::string> explode(std::string const&content, char const carac);
int nbOccurrence(std::string const&content, char const carac);
std::string delOccurrence(std::string const&content, char const carac);
std::string replaceOccurrence(std::string const&content, std::string const str,std::string const newStr);
std::string replaceOccurrence(std::string const&content, char const carac,char const newCarac);

//time.cpp
void delay(unsigned long ms);


} // Fin du namespace

#endif // FASTWAY_HPP_INCLUDED
