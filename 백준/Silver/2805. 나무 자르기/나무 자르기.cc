#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, l[1000002];

bool solve(int t){
  ll ans = 0;
  for(int i = 0 ; i < n ; ++i){
    if(l[i] > t) ans += l[i] - t;
  }
  if(ans >= m) return true;
  return false;
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> n >> m;

  for(int i = 0 ; i < n ; ++i)
    cin >> l[i];

  ll st = 0;
  ll en = *max_element(l, l+n);

  while(st < en){
    ll mid = (st + en + 1) / 2;
    if(solve(mid))
      st = mid;
    else
      en = mid - 1;
  }

  cout << st;
}