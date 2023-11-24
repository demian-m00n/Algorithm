#include<bits/stdc++.h>
using namespace std;

int d[1005];
int n;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;

  d[1] = 1;

  for(int i = 2 ; i <= n ; ++i){
    d[i] = 1 - d[i-1];
  }

  if(d[n]) cout << "SK";
  else cout << "CY";
}