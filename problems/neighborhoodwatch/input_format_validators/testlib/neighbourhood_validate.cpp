#include "testlib.h"
#include <bits/stdc++.h>

#include "bounds.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  
  int n = inf.readInt(MIN_N, MAX_N, "n");
  inf.readSpace();
  int k = inf.readInt(MIN_K, n, "K");
  inf.readEoln();

  set<int> locs;
  for(int i=0;i<k;i++){
    int l = inf.readInt(1, n);
    inf.readEoln();
    ensuref(locs.count(l) == 0, "No duplicates!");
    locs.insert(l);
    ensuref(*locs.rbegin() == l, "Input is not sorted!");
  }
  
  inf.readEof();

  return OK_EXIT_CODE;
}
