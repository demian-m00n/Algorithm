#include<bits/stdc++.h>
using namespace std;
queue<int> Q;
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n ; ++i){
    Q.push(i);
  }

  while(Q.size()!=1){
    Q.pop();
    int tmp = Q.front();
    Q.push(tmp);
    Q.pop();
  }

  cout << Q.front() ;
}