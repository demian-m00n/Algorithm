#include<bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int, string>> v;
int n;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;
  for(int i = 0 ; i < n ; ++i){
    int a, b, c;
    string st;
    cin >> st >> a >> b >> c;
    v.push_back({-a, b, -c, st});
  }

  sort(v.begin(),v.end());

  for(auto x : v){
    cout << get<3>(x) << '\n';
  }
}