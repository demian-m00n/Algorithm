#include<bits/stdc++.h>
using namespace std;

int d[5005];
int board[5005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  string str;
  cin >> str;

  int n = str.size();

  d[0] = 1;

  for(int i = 1 ; i <= n ; ++i) board[i] = str[i-1] - '0';

  for(int i = 1 ; i <= n ; ++i){
    if(board[i] > 0) d[i] = (d[i] + d[i-1]) % 1000000;
    int x = board[i-1] * 10 + board[i];
    if(x >= 10 && x <= 26) d[i] = (d[i] + d[i-2]) % 1000000;
  }

  cout << d[n];
}