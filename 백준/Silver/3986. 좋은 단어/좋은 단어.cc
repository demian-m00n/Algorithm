#include<bits/stdc++.h>
using namespace std;
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n,ans = 0;
  cin >> n;
  while(n--){
    string a;
    stack<char> s;
    cin >> a;
    for(auto c:a){
      if(!s.empty() && s.top()==c){
        s.pop();
      }
      else s.push(c);
    }
    if(s.empty()) ++ans;
  }
  cout << ans;
}
