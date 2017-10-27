#include <iostream>
#include <stdlib.h>
#include "all.h"
using namespace std ;

#define v 5

static int getVerticeRank(int v, int k) { return v*(k+1) + 1; }

static void firstClause(int k) {
  for(int v = 0 ; v < orderG() ; ++v) {
    for(int i = 0 ; i <= k ; ++i) {
      for(int j = 0 ; j <= k ; ++j) {
        if(i == j)
          continue ;
        cout << -(getVerticeRank(v, k)+i) << " " << -(getVerticeRank(v, k)+j) << " " << 0 << endl;
      }
    }
  }
}

static void secondClause(int k) {
  for(int v = 0 ; v < orderG() ; ++v) {
    for(int u = 0 ; u < orderG(); ++u) {
      if(u == v)
        continue ;

      cout << -(getVerticeRank(v, k)) << " " << -(getVerticeRank(u, k)) << " " << 0 << endl ;
    }
  }
}

static void thirdClause(int k) {
  for(int v = 0 ; v < orderG() ; ++v) {
    cout << -(getVerticeRank(v,k)+k) << " " ;
  }
  cout << 0 << endl ;
}

static void forthClause(int k) {
  for(int v = 0 ; v < orderG(); ++v) {
    for(int u = 0 ; u < orderG(); ++u) {
      if(u == v || !(are_adjacent(u, v)))
        continue ;
      for(int i = 0, j = i+1; i < k; ++i, ++j)
      {
        cout << -(getVerticeRank(v,k)+j) << " " << (getVerticeRank(u,k)+i) << " " ;
      }
      cout << 0 << endl;
    }
  }
}

int main(int argc, char const *argv[]) {
  if(argc != 2) {
    return 1 ;
  }
  int k = atoi(argv[1]);

  firstClause(k);
  secondClause(k);
  thirdClause(k);
  forthClause(k);

  return 0;
}
