#include "testlib.h"
#include <bits/stdc++.h>

#include "bounds.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  
  long long n = inf.readLong(MIN_N, MAX_N, "n");
  inf.readSpace();
  
  long long m = inf.readLong(n-1, n * (n-1) / 2, "m");
  inf.readEoln();
  
  inf.readEof();

  return OK_EXIT_CODE;
}
