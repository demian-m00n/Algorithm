#include<bits/stdc++.h>
using namespace std;

int N, M, a, b;
vector<int> adj[32'005];
int indeg[32'005];
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N >> M;

  for(int i = 1 ; i <= M ; ++i){
    cin >> a >> b;
    indeg[b]++;
    adj[a].push_back(b);
  }

  priority_queue<int,vector<int>,greater<int>> pq;

  for(int i = 1 ; i <= N ; ++i)
    if(indeg[i] == 0) pq.push(i);

  while(!pq.empty()){
    int cur = pq.top(); pq.pop();
    cout << cur << ' ';
    for(int nxt : adj[cur]){
      indeg[nxt]--;
      if(indeg[nxt] == 0) pq.push(nxt);
    }
  }

}