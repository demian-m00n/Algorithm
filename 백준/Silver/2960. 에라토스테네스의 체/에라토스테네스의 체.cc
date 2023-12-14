#include<bits/stdc++.h>
using namespace std;

int n, k;
bool board[1002];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> k;

  int i = 2;
  int ans = 0;

  while(k > 0){
    if(board[i] == true){
      ++i;
      continue;
    }

    for(int j = i; j <= n && k > 0; j += i){
      if(board[j]) continue;
      board[j] = true;
      ans = j;
      --k;
    }

    ++i;
  }

  cout << ans;
}