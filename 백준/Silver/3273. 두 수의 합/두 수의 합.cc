#include<bits/stdc++.h>
using namespace std;
int n , m ;
bool o[2000001];
int a[1000001]={};
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int cnt = 0 ;
  cin >> n ;
  for(int i = 0 ; i < n ; i ++) cin >> a[i];
  cin >> m;

  for(int i = 0 ; i < n ; i ++) {
    if(m-a[i] > 0 && o [m-a[i]]) cnt ++;
    o[a[i]] = true;
  }
  cout << cnt ;
}