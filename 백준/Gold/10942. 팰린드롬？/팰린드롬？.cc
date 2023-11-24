#include<bits/stdc++.h>
using namespace std;

int n;
int board[2005];
bool d[2005][2005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;

  for(int i = 1 ; i <= n ; ++i){
    cin >> board[i];
    d[i][i] = true;
    if(board[i-1] == board[i]) d[i-1][i] = true;
  }

  for(int i = 2 ; i < n  ; ++i){
    for(int j = 1 ; j <= n - i ; ++j){
      if(board[j] == board[i + j] && d[j + 1][i + j - 1]) d[j][i + j] = true;
    }
  }

  int t;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;
    if(d[a][b])
      cout << 1 << '\n';
    else
      cout << 0 << '\n';
  }
}