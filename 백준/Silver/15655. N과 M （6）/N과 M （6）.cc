#include<bits/stdc++.h>
using namespace std;

int arr[8];
int num[8];
bool isUsed[8];
int n , m;

void solve(int x){
  if(x==m){
    for(int i=0;i<m;++i)
      cout << arr[num[i]] << ' ';
    cout << '\n';
    return ;
  }
  int start = 0;
  if(x!=0) start = num[x-1] + 1;
  for(int i = start; i < n ; ++i){
    if(isUsed[i]) continue;
    isUsed[i] = true;
    num[x] = i;
    solve(x+1);
    isUsed[i] = false;
  }
}


int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m ;
  for(int i = 0 ; i < n ; ++i)
    cin >> arr[i];

  sort(arr,arr+n);
  solve(0);
}