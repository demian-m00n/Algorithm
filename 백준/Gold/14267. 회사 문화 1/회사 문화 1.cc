#include<bits/stdc++.h>
using namespace std;

int n, m, e, w;
int co[100005];
int p[100005];
vector<int> em[100005];

void dfs(int cur){
  if(cur != 1){
    co[cur] += co[p[cur]];
  }
  for(int nxt : em[cur]){
    dfs(nxt);
  }
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;

  for(int i = 1 ; i <= n ; ++i){
    cin >> p[i];
    if(p[i] == -1) continue;
    em[p[i]].push_back(i); 
  }

  while(m--){
    cin >> e >> w;
    co[e] += w;
  }

  dfs(1);

  for(int i = 1 ; i <= n ; ++i)
    cout << co[i] << ' ';
}