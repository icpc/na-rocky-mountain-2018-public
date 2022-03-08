#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
  int n = 250, m = 250, k = 1000000 / m, r = 1000000;
  cout << n << " " << m << endl;
  cout << k << " " << r << endl;

  // The only question is how large the last segment is...
  int last_seg = 0;
  if(argc == 3){
    int seed = atoi(argv[1]);
    srand(seed);
    last_seg = rand() % 1000000 + 1;
  } else if(argc == 2){
    last_seg = atoi(argv[1]);
  } else {
    assert(false);
  }
  
  for(int i=0;i<n-1;i++) cout << k-1 << "\n";
  cout << last_seg << endl;

  for(int i=0;i<n-1;i++) cout << 1000000 << " " << -1000000/250+1 << endl;

  cerr << last_seg << endl;
}
