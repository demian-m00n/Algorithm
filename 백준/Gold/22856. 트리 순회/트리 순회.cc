#include<bits/stdc++.h>
using namespace std;

const int MXN = 100'005, ROOT = 1;
int N, p, l, r;
int lc[MXN];
int rc[MXN];
int pr[MXN];
vector<bool> vis(MXN);

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> N;
  pr[ROOT] = -1;
  for(int i = 0 ; i < N ; ++i){
    cin >> p >> l >> r;
    lc[p] = l;
    rc[p] = r;
    pr[l] = p;
    pr[r] = p;
  }

  int endpoint = ROOT;
  while(rc[endpoint] != -1)
    endpoint = rc[endpoint];

  int cur = ROOT, move = 0;
  while(1){
    vis[cur] = true;
    move++;
    if(lc[cur] != -1 && !vis[lc[cur]])
      cur = lc[cur];
    else if(rc[cur] != -1 && !vis[rc[cur]])
      cur = rc[cur];
    else{
      if(cur == endpoint)
        break;
      else
        cur = pr[cur];
    }
  }

  cout << move - 1;
}