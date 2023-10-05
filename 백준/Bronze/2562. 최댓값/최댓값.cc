#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int mx = 0 ; int ans = 0 ;
  for(int i = 1 ; i <= 9 ; ++i){
    int n ;
    cin >> n ;
    if(mx<n){
      ans = i ;
      mx = max(mx,n) ;
    }
  }

  cout << mx << '\n' << ans ;
}