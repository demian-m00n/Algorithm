#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
int d[1000005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> t;
  
  while(t--){
    fill(d,d+1000005,0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
      cin >> d[i];

    ll ans = 0;
    int mx = 0;
    for(int i = n-1 ; i >= 0 ; --i){
      if(mx < d[i]) mx = d[i];
      else ans += (ll)(mx - d[i]);
    }

    cout << ans << '\n';
  }

}