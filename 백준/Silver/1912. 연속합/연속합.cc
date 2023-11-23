#include<bits/stdc++.h>
using namespace std;

int d[100005] , sum[100005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n ;
  cin >> n;
  for(int i = 1 ; i <= n ; ++i){
    cin >> d[i];
    sum[i] = d[i];
  }

  for(int i = 1 ; i <=n ;  ++i){
    sum[i] = max(sum[i], sum[i-1] + d[i]);
  }

  cout << *max_element(sum+1,sum+n+1);

}