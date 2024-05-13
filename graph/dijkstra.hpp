#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct edge{
  ll to;
  ll cost;
};

template<typename T, typename U>
vector<T> dijkstra(vector<vector<edge>> G, U s, T a){
  U N = G.size();
  vector<T> dist(N, INF);
  dist[s] = 0;
  priority_queue<pair<T, U>, vector<pair<T, U>>, greater<pair<T, U>>> q;
  q.emplace(0, s);
  while(!q.empty()){
    auto [d, x] = q.top();q.pop();
    if(d>dist[x]) continue;
    for(auto [nx, cost] : G[x]){
      if(d+cost<dist[nx]){
        dist[nx] = cost+d;
        q.emplace(dist[nx], nx);
      }
    }
  }
  return dist;
}