// If you only use values that are present in the input, you should be wrong

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;

  vector<int> A(n);
  for(auto& x : A) cin >> x;
  
  sort(begin(A), end(A));
  
  int ans = 0;
  for(int i=n-1;i>=0;i--){
    int h = A[i];
    if(h > n) continue;
    if(h == 0) continue;
    if(A[n-h] >= h)
      ans = max(ans,h);
  }
  cout << ans << endl;
}
