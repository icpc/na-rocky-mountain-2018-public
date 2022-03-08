#include <bits/stdc++.h>
#include "testlib.h"

#include "bounds.h"

using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  
  long long n = inf.readLong(MIN_N, MAX_N, "n");
  inf.readSpace();
  
  long long k = inf.readLong(MIN_K, MAX_K, "k");
  inf.readEoln();
  
  long long fact=1; // Need to ensure (n-1)! >= k
  for(int i=1;i<=n-1;i++){
    if(fact >= k) break;
    if(LLONG_MAX / fact < i) fact = LLONG_MAX;
    else fact *= i;
  }
  ensuref(fact >= k, "Not enough sequences!");
  
  inf.readEof();

  return OK_EXIT_CODE;
}
