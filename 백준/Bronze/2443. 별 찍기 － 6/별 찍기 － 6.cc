#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n ;
  cin >> n ;
  for(int i = n ; i > 0 ; --i){

    for(int k = n - i ; k > 0 ; --k) cout << ' ' ;
    for(int j = 0 ; j < 2 * i - 1 ; ++j ) cout << '*' ;

    cout << '\n' ;
  }
}