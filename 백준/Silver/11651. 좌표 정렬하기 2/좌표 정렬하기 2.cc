#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n;
  cin >> n;
  pair<int,int> x[n];
  for(auto &s : x) cin >> s.first >> s.second;

  sort(x, x+n, [&](pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
  });

  for(auto s : x){
    cout << s.first << ' ' << s.second << '\n';
  }
}