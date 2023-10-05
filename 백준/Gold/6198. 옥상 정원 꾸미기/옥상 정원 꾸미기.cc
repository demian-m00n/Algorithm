#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;

int n ;
stack<int> S ;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> n ;
  
  ll tot = 0 ;

  while(n--){
    ll h ;
    cin >> h ;
    while(!S.empty() && S.top() <= h)
      S.pop() ;
    tot += S.size() ;
    S.push(h) ;
  }

  cout << tot ;
}