#include<bits/stdc++.h>
using namespace std;
int sum[1005] , d[1005];
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  int n ;
  cin >> n;
  for(int i = 0 ; i < n ; ++i){
    cin >> d[i];
    sum[i] = d[i];
  }
  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < i ; ++j){
      if(d[j] < d[i]) sum[i] = max(sum[i], sum[j] + d[i]);
    }
  }

  cout << *max_element(sum,sum+n);
}