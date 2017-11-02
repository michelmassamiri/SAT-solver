#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "all.h"
using namespace std ;


int nbClauses = 0;

int usage(string c)
{
  cout << "Usage : " << c << " k (outFile)" << endl;
  return 1;
}

static int getVerticeRank(int v, int k) { return v*(k+1) +1 ; }

static int getNbClauses(int k) {
  //firt Contrainte
  for(int v = 0 ; v < orderG() ; ++v) {
    for(int i = 0 ; i <= k ; ++i) {
      for(int j = 0 ; j <= k ; ++j) {
        if(i == j)
          continue ;
        nbClauses++;
      }
    }
  }

  //Second Contrainte
  for(int v = 0 ; v < orderG() ; ++v) {
    for(int u = 0 ; u < orderG(); ++u) {
      if(u == v)
        continue ;

      nbClauses++;
    }
  }
  nbClauses++;
  //Third Contrainte
  nbClauses++;

  //forth Contrainte

  for(int v = 0; v < orderG(); ++v)
  {
    for(int i = 1; i <= k; ++i)
      nbClauses++;
  }

  nbClauses += orderG();

  return nbClauses ;
}

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

  for(int v = 0; v < orderG(); ++v)
  {
    f += to_string(getVerticeRank(v, k));
    f += " ";
  }
  f += "0\n";

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

  for(int v = 0; v < orderG(); ++v)
  {
    for(int j = 1; j <= k; ++j)
    {
      f += to_string(getVerticeRank(v,k)); f+= " ";
      for(int u = 0; u < orderG(); ++u)
      {
        if(u == v || are_adjacent(v, u) == 0)
          continue;
        f += to_string(-(getVerticeRank(v, k)+j)); f += " ";
        f += to_string((getVerticeRank(u, k)+(j-1))); f += " ";
      }
      f+= "0\n";
    }
  }

  for(int v = 0; v < orderG(); ++v)
  {
    for(int i = 0; i <= k; ++i)
      {
         f += to_string(getVerticeRank(v, k)+i);
         f += " ";
      }
    f += "0\n";
  }


  return f;
}

int main(int argc, char const *argv[]) {
  if(argc < 2)
  {
    string arg = argv[0];
    return usage(arg);
  }
  int k = atoi(argv[1]);
  string fileName = "test.dimacs";
  if(argc == 3)
    fileName = argv[2];

  ofstream file(fileName);

  file << "p cnf " << orderG()*(k+1) << " " << getNbClauses(k) <<endl ;

  file << firstClause(k);
  file << secondClause(k);
  file << thirdClause(k);
  file << forthClause(k);

  //file.seekp(0, ios::beg);
  //file << "c" << endl ;
  //file << "p cnf " << orderG()*(k+1) << " " << nbClauses ;

  return 0;
}
