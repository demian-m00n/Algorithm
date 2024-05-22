#include<bits/stdc++.h>
using namespace std;

int n, q, op, x;
set<int> sight;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> q;
  for(int i = 1 ; i <= n; ++i){
    cin >> x;
    if(x) sight.insert(i);
  }
  int dohyun = 1;
  while(q--){
    cin >> op;
    if(op == 1){
      cin >> x;
      if(sight.find(x) == sight.end()) sight.insert(x);
      else sight.erase(x);
    }
    else if(op == 2){
      cin >> x;
      dohyun = (dohyun + x - 1) % n + 1;
    }
    else if(op == 3){
      if(sight.empty()) cout << -1 << '\n';
      else{
        auto it = sight.lower_bound(dohyun);
        if(it != sight.end())
          cout << *it - dohyun << '\n';
        else
          cout << n - dohyun + *sight.begin() << '\n';
      }
    }
  }
}