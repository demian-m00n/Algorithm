#include<bits/stdc++.h>
using namespace std;

int n , m ;
vector<int> adj[32005];
int ind[32005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m ;
  while(m--){
    int u , v ;
    cin >> u >> v ;
    adj[u].push_back(v);
    ind[v]++;
  }

  queue<int> Q;
  
  for(int i = 1 ; i <= n ; ++i){
    if(ind[i]==0) Q.push(i);
  }

  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    cout << cur << ' ';
    for(int nxt : adj[cur]){
      ind[nxt]--;
      if(ind[nxt]==0) Q.push(nxt);
    }
  }
}