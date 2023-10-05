#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int a , b , c ;
  cin >> a >> b >> c ;
  
  if(a==b&&b==c) cout << 10000+1000*a;
  else if(a!=b&&b!=c&&c!=a) cout << 100*max(a,max(b,c));
  else if(a==b) cout << 1000+100*a;
  else cout << 1000+100*c;

}