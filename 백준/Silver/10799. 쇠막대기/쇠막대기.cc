#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  string a;
  ll ans = 0;
  stack<char> s;
  cin >> a;
  int al = a.length();
  for(int i=0;i<al;++i){
    if(a[i]=='(') s.push(a[i]);
    else{
      if(a[i-1]=='('){
        s.pop();
        ans+=s.size();
      }
      else{
        s.pop();
        ++ans;
      }
    }
  }
  cout << ans ;
}