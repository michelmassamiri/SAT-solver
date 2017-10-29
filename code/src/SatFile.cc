#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "all.h"
using namespace std ;


int nbClauses = 0;

int usage(string c)
{
  cout << "Usage : " << c << " k (outFile)" << endl;
  return 1;
}

static int getVerticeRank(int v, int k) { return v*(k+1) + 1; }

static string firstClause(int k) {
  string f = "";
  for(int v = 0 ; v < orderG() ; ++v) {
    for(int i = 0 ; i <= k ; ++i) {
      for(int j = 0 ; j <= k ; ++j) {
        if(i == j)
          continue ;
        f += to_string(-(getVerticeRank(v, k)+i)); f += " "; f += to_string(-(getVerticeRank(v, k)+j)); f += " 0\n";
        nbClauses++;
      }
    }
  }
  return f;
}

static string secondClause(int k) {
  string f = "";
  for(int v = 0 ; v < orderG() ; ++v) {
    for(int u = 0 ; u < orderG(); ++u) {
      if(u == v)
        continue ;

      f += to_string(-(getVerticeRank(v, k))); f += " "; f += to_string(-(getVerticeRank(u, k))); f += " 0\n";
      nbClauses++;
    }
  }
  return f;
}

static string thirdClause(int k) {
  string f = "";
  for(int v = 0 ; v < orderG() ; ++v) {
    f += to_string((getVerticeRank(v,k)+k)); f+= " " ;
  }
  f += "0\n";
  nbClauses++;
  return f;
}

static string forthClause(int k) {
  string f = "";
  for(int v = 0 ; v < orderG(); ++v) {
    for(int u = 0 ; u < orderG(); ++u) {
      if(u == v || !(are_adjacent(u, v)))
        continue ;
      for(int i = 0, j = i+1; i < k; ++i, ++j)
      {
        f += to_string(-(getVerticeRank(v,k)+j)); f += " "; f += to_string((getVerticeRank(u,k)+i)); f += " " ;
      }
      f += "0\n";
      nbClauses++;
    }
  }
  return f;
}

int main(int argc, char const *argv[]) {
  if(argc != 2)
  {
    string arg = argv[0];
    return usage(arg);
  }
  int k = atoi(argv[1]);
  string fileName = "test.dimacs";
  if(argc == 3)
    fileName = argv[2];

  ofstream file(fileName);

  file << firstClause(k);
  file << secondClause(k);
  file << thirdClause(k);
  file << forthClause(k);


  file.seekp(ios::beg);
  file << "p cnf " << orderG()*(k+1) << " " << nbClauses << endl;

  return 0;
}
