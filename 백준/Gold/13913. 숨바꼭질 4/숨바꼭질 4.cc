#include<bits/stdc++.h>
using namespace std;

int dist[100003];
int pre[100003];
bool vis[100003];
int n, k;

int main(void){
  cin >> n >> k;

  dist[n] = 0;
  vis[n] = true;

  queue<int> Q;
  Q.push(n);

  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    if(cur == k) break;
    for(int nxt : {cur - 1, cur + 1, 2 * cur}){
      if(nxt < 0 || nxt > 100000)
        continue;
      if(vis[nxt] || dist[nxt] > 0)
        continue;
      dist[nxt] = dist[cur] + 1;
      pre[nxt] = cur;
      vis[nxt] = true;
      Q.push(nxt);
    }
  }

  while(!Q.empty()) Q.pop();

  cout << dist[k] << '\n';
  
  vector<int> ans;
  int cur = k;

  while(true){
    if(cur == n) break;
    ans.push_back(cur);
    cur = pre[cur];
  }

  cout << n << ' ';

  reverse(ans.begin(),ans.end());
  for(int x : ans)
    cout << x << ' ';
}