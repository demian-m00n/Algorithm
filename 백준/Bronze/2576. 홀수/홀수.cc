#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int tot = 0 ;
  int mn = 101 ;

  for(int i = 0 ; i < 7 ; ++i){
    int n ;
    cin >> n ;
    if(n%2==1){
      tot+=n ;
      mn = min(mn,n);
    }
  }

  if(tot == 0) cout << -1 ;
  else cout << tot << '\n' << mn ;
}