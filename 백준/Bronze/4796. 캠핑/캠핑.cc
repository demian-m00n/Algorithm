#include<bits/stdc++.h>
using namespace std;

int l, p, v;

int main(void){

  int t = 1;

  while(1){
    cin >> l >> p >> v;
    if( l == 0 && p == 0 && v ==0)
      break;
    
    int ans = (v / p) * l + min(v % p, l);

    cout << "Case " << t << ": " << ans << '\n';
    ++t;
  }

}