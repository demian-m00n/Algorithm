#include<bits/stdc++.h>
using namespace std;

int a[103];

int t, n;

int gcd(int x, int y){
  if(y == 0) return x;
  else return gcd(y,x% y);
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> t;

  while(t--){
    cin >> n;
    
    for(int i = 0 ; i < n ; ++i)
      cin >> a[i];

    long long ans = 0;

    sort(a, a+n);

    for(int i = 0 ; i < n ; ++i){
      for(int j = i+ 1; j < n ; ++j){
        ans += gcd(a[i],a[j]);
      }
    }

    cout << ans << '\n';
  }
}