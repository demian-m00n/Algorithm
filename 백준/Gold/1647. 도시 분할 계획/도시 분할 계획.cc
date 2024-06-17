#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector<pair<int,int>> adj[100'002];
bool chk[100'002];
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
int N, M;
int cost, a, b;
int cnt = 0;
long long ans = 0;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N >> M;

  for(int i = 0 ; i < M ; ++i){
    cin >> a >> b >> cost;
    adj[b].push_back({cost, a});
    adj[a].push_back({cost, b});
  }

  chk[1] = 1;
  int mxc = 0;

  for(auto nxt : adj[1])
    pq.push({nxt.X, 1, nxt.Y});

  while(cnt < N - 1){
    tie(cost, a, b) = pq.top(), pq.pop();
    if(chk[b]) continue;
    chk[b] = 1;
    cnt++;
    mxc = max(mxc,cost);
    ans += cost;
    for(auto nxt : adj[b]){
      if(!chk[nxt.Y])
        pq.push({nxt.X, b, nxt.Y});
    }
  }

  cout << ans - mxc;
}