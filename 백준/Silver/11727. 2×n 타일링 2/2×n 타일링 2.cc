#include<bits/stdc++.h>
using namespace std;

int board[1003];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n;
  cin >> n;
  board[1] = 1;
  board[2] = 3;
  for(int i = 3 ; i <= n ; ++i) board[i] = (board[i-1] + board[i-2] * 2) % 10007;
  cout << board[n] ;

}