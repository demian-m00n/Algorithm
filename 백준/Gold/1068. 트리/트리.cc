#include<bits/stdc++.h>
using namespace std;

vector<int> child[52];
int N, a, del, ans = 0, root;

void dfs(int cur){
  if(cur == del) return;
  if(child[cur].empty()){
    ans++;
    return;
  }
  if(child[cur].size() == 1 && child[cur][0] == del){
    ans++;
    return;
  }
  for(int nxt : child[cur]){
    dfs(nxt);
  }
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N;

  for(int i = 0 ; i < N ; ++i){
    cin >> a;
    if(a == -1){
      root = i;
      continue;
    }
    child[a].push_back(i);
  }

  cin >> del;

  dfs(root);

  cout << ans;

}