#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int t, n;
  string name, category;
  cin >> t;
  while(t--){
    int ans = 1;
    cin >> n;
    unordered_map<string,int> hb{};
    for(int i = 0 ; i < n ; ++i){
      cin >> name >> category;
      hb[category]++;
    }
    for(auto x : hb) ans *= x.second + 1;
    cout << ans - 1 << '\n';
  }
}