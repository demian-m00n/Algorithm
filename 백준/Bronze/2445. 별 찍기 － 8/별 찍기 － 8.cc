#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n ;
  cin >> n ;
  for(int i = 1 ; i <= n ; ++i){

    for(int j = 0 ; j < i ; ++j ) cout << '*' ;
    for(int k = 2 * n ; k > 2 * i ; --k) cout << ' ' ;
    for(int j = 0 ; j < i ; ++j ) cout << '*' ;

    cout << '\n' ;
  }

  for(int i = n - 1 ; i > 0 ; --i){

    for(int j = 0 ; j < i ; ++j ) cout << '*' ;
    for(int k = 2 * n ; k > 2 * i ; --k) cout << ' ' ;
    for(int j = 0 ; j < i ; ++j ) cout << '*' ;

    cout << '\n' ;
  }
}