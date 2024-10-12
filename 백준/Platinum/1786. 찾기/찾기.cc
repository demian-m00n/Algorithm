#include <bits/stdc++.h>
using namespace std;

vector<int> failure(string &s){
  int j = 0;
  vector<int>f(s.size());

  for(int i = 1 ; i < (int)s.size() ; ++i){
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) f[i] = ++j;
  }

  return f;
}


int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s, p;
  getline(cin, s);
  getline(cin, p);
  int j = 0 ;
  vector<int> result;
  vector<int> f = failure(p);
  for(int i = 0 ; i < (int)s.size() ; ++i){
    while(j > 0 && s[i] != p[j]) j = f[j - 1];
    if(s[i] == p[j]) ++j;
    if(j == (int)p.size()){
      result.push_back(i + 1 - j);
      j = f[j - 1];
    }
  }

  cout << result.size() << '\n';
  for(int x : result)
    cout << x + 1 << ' ';

  return 0;
}