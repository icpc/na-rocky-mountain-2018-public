#include <bits/stdc++.h>
#include "testlib.h"

#include "bounds.h"

using namespace std;

bool connected(const vector< vector<int> > & V){
   vector<bool> seen; seen.resize(V.size(), false);
   stack<int> S;
   S.push(0); seen[0] = true;
   while(!S.empty()){
      int cur = S.top(); S.pop();
      for(int i = 0; i < (int)V[cur].size(); i++){
	 int nxt = V[cur][i];
	 if(!seen[nxt]){
	    seen[nxt] = true;
	    S.push(nxt);
	 }
      }
   }
   for(int i = 0; i < (int)seen.size(); i++)
      if(!seen[i])
	return false;
   return true;
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(MIN_N, MAX_N, "n");
    inf.readSpace();
    int m = inf.readInt(MIN_M, MAX_M, "m");
    inf.readEoln();

    set <pair<int, int> > seen;
    set<char> seenC;
    vector< vector< int > > V; V.resize(n);
    for(int i = 0; i < m; i++){
       int u = inf.readInt(1, n, "u");
       inf.readSpace();
       int v = inf.readInt(1, n, "v");
       inf.readSpace();
       inf.readInt(MIN_D, MAX_D, "d");
       inf.readSpace();
       char c = inf.readChar();
       ensuref(c == 'R' or c == 'O' or c == 'Y' or c == 'G' or c == 'B'
	       or c == 'I' or c == 'V', "Not a proper color");
       seenC.insert(c);
       inf.readEoln();
       ensuref( u < v, "u >= v");
       ensuref( seen.find( make_pair(u,v) ) == seen.end(), "repeat edge");
       seen.emplace(u,v);
       V[u-1].push_back(v-1);
       V[v-1].push_back(u-1);
    }
    ensuref( seenC.size() == 7, "not every colour was seen");
    ensuref( connected(V) , "not connected");
    inf.readEof();

  return OK_EXIT_CODE;
}
