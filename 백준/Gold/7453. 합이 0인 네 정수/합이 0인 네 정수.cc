#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
int a[4002], b[4002], c[4002], d[4002];
int ab[16000002], cd[16000002];

int main(){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cd[i*n + j] = c[i] + d[j];

  sort(cd, cd + n*n);
  
  ll ans = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      ans += upper_bound(cd, cd + n*n, -a[i] - b[j]) - lower_bound(cd, cd + n*n, -a[i] - b[j]);

  cout << ans;
}