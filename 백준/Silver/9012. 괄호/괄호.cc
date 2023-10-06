#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n ;
  cin >> n ;
  while(n--){
    string str ;
    cin >> str ;
    stack<char> s;
    bool isVPS = true ;
    for(auto c : str){
      if(c == '(') s.push('(') ;
      else if(c == ')' && !s.empty()) s.pop() ;
      else{
        isVPS = false ;
        break;
      }
    }

    if(!s.empty()) isVPS = false ;

    if(isVPS) cout << "YES\n" ;
    else cout << "NO\n" ;
  }
}