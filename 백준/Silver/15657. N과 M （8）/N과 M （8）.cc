#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int isUsed[10];
int num[10];

void func(int k){
  if(k == m){
    for(int i = 0 ; i < m ; ++i)
      cout << num[i] << ' ';
    cout << '\n';
    return ;
  }
  int pre = (k == 0) ? 0 : k - 1;
  for(int i = 0 ; i < n ; ++i){
    if(isUsed[i] == m) continue;
    if(num[pre] > arr[i]) continue;
    num[k] = arr[i];
    ++isUsed[i];
    func(k+1);
    --isUsed[i];
  }
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> m;
  for(int i = 0 ; i < n ; ++i)
    cin >> arr[i];
  sort(arr,arr+n);
  func(0);
}