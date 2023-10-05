#include<bits/stdc++.h>
using namespace std;

int n ;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n ;
  int m = 0 , y = 0 ;
  while(n--){
    int t ;
    cin >> t ;
    y += (t/30+1) * 10 ;
    m += (t/60+1) * 15 ;
  }

  if(m > y) cout << "Y " << y ;
  else if(m < y) cout << "M " << m ;
  else cout << "Y M " << y ;

}