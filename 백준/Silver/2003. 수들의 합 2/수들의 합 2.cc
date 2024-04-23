#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[10002];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  for(int i = 0 ; i < n ; ++i) cin >> a[i];

  int st = 0, en = 1, sum = a[0], ans = 0;

  while(1){
    if(sum == m) ++ans;
    if(sum <= m) sum += a[en++];
    if(sum > m) sum -= a[st++];
    if(en == n + 1) break;
  }

  cout << ans;
}