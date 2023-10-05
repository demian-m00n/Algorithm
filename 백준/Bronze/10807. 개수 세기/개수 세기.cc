#include<bits/stdc++.h>
using namespace std;

int arr[102];
int n;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;
  for(int i = 0 ; i < n ; ++i) cin >> arr[i];
  int v;
  cin >> v;
  int ans = 0 ;
  for(int i = 0 ; i < n ; ++i)
    if(arr[i]==v) ++ans;
  
  cout << ans ;
}