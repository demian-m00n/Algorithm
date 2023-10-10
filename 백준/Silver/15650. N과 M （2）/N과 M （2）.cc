#include<bits/stdc++.h>
using namespace std;
int arr[9];
bool isUsed[9];
int n , m ;

void solve(int x){
  if(x == m){
    for(int i = 0;i < m; ++i)
      cout << arr[i] << ' ';
    cout << '\n';
    return ;
  }
  int start = 1;
  if( x!=0 ) start = arr[x-1] + 1 ;
  for(int i = start; i<=n; ++i){
    if(isUsed[i]) continue;
    arr[x] = i;
    isUsed[i] = true;
    solve(x+1);
    isUsed[i] = false;
  }
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  solve(0);
}