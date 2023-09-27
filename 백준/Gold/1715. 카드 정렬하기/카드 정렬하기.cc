#include<bits/stdc++.h>
using namespace std;

int n;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  priority_queue<int,vector<int>,greater<int>> pQ;
  cin >> n ;
  while(n--){
    int t;
    cin >> t;
    pQ.push(t);
  }
  int ans = 0;
  while(pQ.size()>1){
    int a = pQ.top(); pQ.pop();
    int b = pQ.top(); pQ.pop();
    ans += a + b;
    pQ.push(a+b);
  }
  cout << ans ;
}