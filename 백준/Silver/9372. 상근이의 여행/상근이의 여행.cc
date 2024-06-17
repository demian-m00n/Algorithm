#include<bits/stdc++.h>
using namespace std;

int T, N, M, u, v;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> T;

  while(T--){
    cin >> N >> M;
    for(int i = 0 ; i < M ; ++i){
      cin >> u >> v;
    }
    cout << N - 1 << '\n';
  }
}