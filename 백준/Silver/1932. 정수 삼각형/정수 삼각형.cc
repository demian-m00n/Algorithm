#include<bits/stdc++.h>
using namespace std;

int board[501][501];
int table[501][501];

int main(void){
  int n ;
  cin >> n ;

  for(int i = 0 ; i < n ; ++i){
    for(int j = 0  ; j < i + 1 ; ++j){
      cin >> board[i][j];
      table[i][j] = board[i][j];
    }
  }

  for(int i = 1 ; i < n ; ++i){
    for(int j = 0  ; j < i + 1 ; ++j){
      if( j == 0 ){
        table[i][j] = table[i-1][j]+table[i][j];
      }
      else if( j == i ){
        table[i][j] = table[i-1][j-1]+table[i][j];
      }
      else{
      table[i][j] = max(table[i-1][j]+table[i][j],table[i-1][j-1]+table[i][j]);
      }
    }
  }

  int mx = 0;
  for(int i = 0 ; i < n ; ++i){
    mx = max(mx,table[n-1][i]);
  }

  cout << mx ;
}