#include<bits/stdc++.h>
using namespace std;

int N, M, a, b, isDownhill;
vector<pair<int,int>> adj[1002];
bool chk[1002];


int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N >> M;

  for(int i = 0 ; i <= M ; ++i){
    cin >> a >> b >> isDownhill;
    adj[a].push_back({isDownhill, b});
    adj[b].push_back({isDownhill, a});
  }

  long long worst = 0, best = 0;

  int cnt = 0;

  fill(chk, chk + N + 1, 0);
  priority_queue<tuple<int,int,int>> mxpq;
  priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> mnpq;

  chk[0] = 1;
  for(auto nxt : adj[0])
    mxpq.push({nxt.first, 0, nxt.second});

  while(cnt < N){
    int isDh, aa, bb;
    tie(isDh, aa, bb) = mxpq.top(); mxpq.pop();
    if(chk[bb]) continue;
    ++cnt;
    chk[bb] = 1;
    if(!isDh) ++best;
    for(auto nxt : adj[bb]){
      if(!chk[nxt.second])
        mxpq.push({nxt.first, bb, nxt.second});
    }
  }

  fill(chk, chk + N + 1, 0);
  cnt = 0;

  chk[0] = 1;
  for(auto nxt : adj[0])
    mnpq.push({nxt.first, 0, nxt.second});

  while(cnt < N){
    int isDh, aa, bb;
    tie(isDh, aa, bb) = mnpq.top(); mnpq.pop();
    if(chk[bb]) continue;
    ++cnt;
    chk[bb] = 1;
    if(!isDh) ++worst;
    for(auto nxt : adj[bb]){
      if(!chk[nxt.second])
        mnpq.push({nxt.first, bb, nxt.second});
    }
  }

  worst *= worst;
  best *= best;

  cout << worst - best;
}