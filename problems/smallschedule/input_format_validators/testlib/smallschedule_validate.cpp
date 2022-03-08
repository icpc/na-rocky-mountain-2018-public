#include "testlib.h"
#include <bits/stdc++.h>

#include "bounds.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  
  inf.readInt(MIN_Q, MAX_Q, "Q");
  inf.readSpace();
  inf.readInt(MIN_M, MAX_M, "M");
  inf.readSpace();
  inf.readInt(MIN_S, MAX_S, "S");
  inf.readSpace();
  inf.readInt(MIN_L, MAX_L, "L");
  inf.readEoln();
  
  inf.readEof();

  return OK_EXIT_CODE;
}
