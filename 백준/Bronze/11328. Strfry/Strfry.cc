#include<bits/stdc++.h>
using namespace std;

int n ;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n ;

  while(n--){
    int alph[26] {} ;

    string s1 , s2 ;
    cin >> s1 >> s2 ;

    for(auto c : s1) ++alph[c-'a'] ;
    for(auto c : s2) --alph[c-'a'] ;

    bool isPossible = true ;

    for(int i = 0 ; i < 26 ; ++i){
      if(alph[i]!=0){
        isPossible = false ;
        break;
      }
    }

    if(isPossible) cout << "Possible\n" ;
    else cout << "Impossible\n" ;
  }
}