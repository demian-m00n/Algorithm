#include<bits/stdc++.h>
using namespace std;
int l[1005] , d[1005];
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  int n ;
  cin >> n;
  for(int i = 0 ; i < n ; ++i){
    cin >> d[i];
  }
  fill(l,l+n,1);
  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < i ; ++j){
      if(d[j] < d[i]) l[i] = max(l[i],1 + l[j]);
    }
  }

  cout << *max_element(l,l+n);
}