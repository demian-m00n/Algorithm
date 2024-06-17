#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int N, cost;
vector<pair<int,int>> adj[1002];
bool chk[1002];
int cnt = 0;
long long ans = 0;
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  
  cin >> N;

  for(int i = 1 ; i <= N ; ++i){
    for(int j = 1 ; j <= N ; ++j){
      cin >> cost;
      if(j > i){
        adj[i].push_back({cost,j});
        adj[j].push_back({cost,i});
      }
    }
  }

  chk[1] = 1;
  for(auto nxt : adj[1])
    pq.push({nxt.X, 1, nxt.Y});

  while(cnt < N - 1){
    int cost, a, b;
    tie(cost, a, b) = pq.top(); pq.pop();
    if(chk[b]) continue;
    chk[b] = 1;
    cnt++;
    ans += cost;
    for(auto nxt : adj[b]){
      if(!chk[nxt.Y])
        pq.push({nxt.X, b, nxt.Y});
    }
  }

  cout << ans;

}