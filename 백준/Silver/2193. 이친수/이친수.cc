#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll board[92];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n ;
  cin >> n;
  board[1]=1;
  board[2]=1;
  board[3]=2;
  for(int i = 4 ; i <=n ; ++i) board[i] = board[i-1] + board[i-2] ;
  cout << board[n] ;
}