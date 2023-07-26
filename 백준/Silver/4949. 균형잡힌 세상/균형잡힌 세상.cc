#include<bits/stdc++.h>
using namespace std;
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  while(1){
    string a;
    getline(cin,a);
    if(a == ".") break;
    bool isValid=true;
    stack<char> s;
    for(auto c:a){
      if(c=='('||c=='[') s.push(c);
      else if(c==')'){
        if(s.empty()||s.top()!='('){
          isValid=false;
          break;
        }
        s.pop();
      }
      else if(c==']'){
        if(s.empty()||s.top()!='['){
          isValid=false;
          break;
        }
        s.pop();
      }
    }
    if(!s.empty()) isValid=false;
    if(isValid) cout<<"yes\n";
    else cout<<"no\n";
  }
}