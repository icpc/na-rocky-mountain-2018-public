#include "testlib.h"
#include <bits/stdc++.h>

#include "bounds.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int n = inf.readInt(MIN_N, MAX_N, "n");
  inf.readEoln();

  for(int i=0;i<n;i++){
    inf.readStrictReal(MIN_Q, MAX_Q, 1, 1);
    inf.readSpace();
    inf.readStrictReal(MIN_Y, MAX_Y, 1, 1);
    inf.readEoln();
  }
  
  inf.readEof();

  return OK_EXIT_CODE;
}
