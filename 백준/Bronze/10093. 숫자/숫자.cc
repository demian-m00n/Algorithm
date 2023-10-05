#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ll a, b;
  cin >> a >> b;
  if (a > b) swap(a,b);
  if (a == b || b - a == 1) cout << 0;
  else {
    cout << b - a - 1 << "\n";
    for(ll i = a+1; i < b; i++)
      cout << i << " ";
  }
}