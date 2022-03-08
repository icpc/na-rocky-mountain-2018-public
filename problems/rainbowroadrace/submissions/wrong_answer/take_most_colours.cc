// Greedily takes the most colours in a Dijkstra-like fashion...

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, pair<int,int> > plii;

vector<vector<pair<ll,pair<int,int> > > > adj;
vector<ll> dist;
vector<int> best_colour_set;

int main(){
  int n, m; cin >> n >> m;
  adj.resize(n);
  dist.assign(n, -1);
  best_colour_set.assign(n, 0);
  
  for(int i=0;i<m;i++){
    int u,v; cin >> u >> v; u--; v--;
    int d; cin >> d;
    char c; cin >> c;
    int colour = string("ROYGBIV").find(c);
    adj[u].emplace_back(d, make_pair(v,colour));
    adj[v].emplace_back(d, make_pair(u,colour));
  }

  priority_queue<plii, vector<plii>, greater<plii> > pq;
  pq.emplace(0,make_pair(0,0));
  
  while(!pq.empty()){
    long long d = pq.top().first;
    int v = pq.top().second.first;
    int colour_set = pq.top().second.second;
    pq.pop();

    int num_colours = __builtin_popcount(colour_set);
    
    if(best_colour_set[v] > num_colours) continue;
    if(best_colour_set[v] < num_colours){
      dist[v] = d;
      best_colour_set[v] = num_colours;
    } else if(best_colour_set[v] == num_colours){
      if(dist[v] != -1 && dist[v] <= d) continue;
      dist[v] = d;
    }
    
    for(const auto& u : adj[v])
      if(best_colour_set[u.second.first] <= __builtin_popcount(colour_set | (1 << u.second.second)))
	pq.emplace(d+u.first, make_pair(u.second.first, colour_set | (1 << u.second.second)));
  }
  
  assert(best_colour_set[0] == 7);
  cout << dist[0] << endl;
}
