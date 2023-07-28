#include<bits/stdc++.h>
using namespace std;
int N;
int cnt[2];
int arr[129][129];

bool chk(int n, int x, int y){
  for(int i = x ; i < x + n ; ++i){
    for(int j = y ; j < y + n ; ++j){
      if(arr[x][y] != arr[i][j]) return false;
    }
  }
  return true;
}

void solve(int n,int x, int y){
  if(chk(n,x,y)){
    ++cnt[arr[x][y]];
    return;
  }
  for(int i = 0 ; i < 2; ++i)
    for(int j = 0 ; j < 2 ; ++j) solve(n/2,x+i*n/2,y+j*n/2);
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N;
  for(int i = 0 ; i < N ; ++i){
    for(int j = 0 ; j < N ; ++j){
        cin >> arr[i][j];
    }
  }
  solve(N,0,0);
  for(int i = 0 ; i < 2 ; ++i) cout << cnt[i] << '\n';
}