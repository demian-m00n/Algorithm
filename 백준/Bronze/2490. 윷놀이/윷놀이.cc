#include<bits/stdc++.h>
using namespace std;

int cnt ;


int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  for(int i = 0 ; i < 3 ; ++i){
    cnt  = 0 ;
    for(int j = 0 ; j < 4 ; ++j){
      int x ;
      cin >> x;
      cnt += x;
    }
    if(cnt==0) cout << 'D';
    else if(cnt==1) cout << 'C';
    else if(cnt==2) cout << 'B';
    else if(cnt==3) cout << 'A';
    else cout << 'E';
    cout << '\n';
  }
}