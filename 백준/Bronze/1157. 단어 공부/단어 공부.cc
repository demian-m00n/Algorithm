#include <bits/stdc++.h>
using namespace std;

unordered_map<char,int> m;
string s;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;

  char ans;
  int mx = 0;

  for(char c : s){
    char upperC = toupper(c);
    if(m.find(upperC) != m.end())
      m[upperC]++;
    else
      m[upperC] = 1;
  }

  for(auto item : m){
    if(item.second > mx){
      ans = item.first;
      mx = item.second;
    }
    else if(item.second == mx)
      ans = '?';
  }

  cout << ans;

  return 0;
}