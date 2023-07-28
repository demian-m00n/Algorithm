#include<bits/stdc++.h>
using namespace std;
int n , m ;
int arr[8];
int num[8];
bool isUsed[8];

void solve(int x){
  if(x==m){
    for(int i=0;i<m;++i)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }
  for(int i=0;i<n;++i){
    if(isUsed[i]) continue;
    isUsed[i] = true;
    arr[x] = num[i];
    solve(x+1);
    isUsed[i] = false;
  }
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  for(int i=0;i<n;++i) cin >> num[i];
  sort(num,num+n);
  solve(0);
}