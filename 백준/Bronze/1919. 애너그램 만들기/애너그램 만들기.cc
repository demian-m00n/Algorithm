#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int alph[26]{};

  string s1, s2;
  cin >> s1 >> s2;

  for (auto c : s1) ++alph[c - 'a'];
  for (auto c : s2) --alph[c - 'a'];

  int cnt = 0 ;

  for (int i = 0; i < 26; ++i) cnt += abs(alph[i]) ;

  cout << cnt ;
}