#include "testlib.h"
#include <bits/stdc++.h>

#include "bounds.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int n = inf.readInt(MIN_N, MAX_N, "n");
  inf.readSpace();
  int m = inf.readInt(MIN_M, MAX_M, "m");
  inf.readEoln();

  inf.readInt(MIN_K, MAX_K, "k");
  inf.readSpace();
  inf.readInt(MIN_R, MAX_R, "r");
  inf.readEoln();

  for(int i=0;i<n;i++){
    inf.readInt(MIN_L, MAX_L, "l");
    inf.readEoln();
  }

  for(int i=0;i<n-1;i++){
    int s = inf.readInt(MIN_S, MAX_S, "s");
    inf.readSpace();
    int c = inf.readInt(MIN_C, MAX_C, "c");
    inf.readEoln();
    ensuref(s + m*c > 0, "s + m*c must be positive.");
  }
  
  inf.readEof();
  
  return OK_EXIT_CODE;
}
