#include<bits/stdc++.h>
using namespace std;

int t;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> t;

  while(t--){
    int x, y;
    cin >> x >> y;

    int d = y - x;
    int ans = 0;
    while(d > 0){
      d -= (int)floor(sqrt(d));
      ans += 1;
    }

    cout << ans << '\n';
  }
}
