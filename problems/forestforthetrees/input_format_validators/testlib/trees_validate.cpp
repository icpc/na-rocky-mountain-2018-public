#include "testlib.h"
#include <bits/stdc++.h>

#include "bounds.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  inf.readLongs(2, MIN_XY, MAX_XY, "brandon");
  inf.readEoln();

  vector<long long> a = inf.readLongs(2, MIN_XY, MAX_XY, "a");
  inf.readSpace();
  vector<long long> b = inf.readLongs(2, MIN_XY, MAX_XY, "b");
  inf.readEoln();

  ensuref(a[0] <= b[0],"x1 <= x2");
  ensuref(a[1] <= b[1],"y1 <= y2");
  
  inf.readEof();

  return OK_EXIT_CODE;
}
