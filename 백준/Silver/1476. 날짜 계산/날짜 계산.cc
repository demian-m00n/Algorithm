#include<bits/stdc++.h>
using namespace std;

int e, s, m;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  
  cin >> e >> s >> m;

  e--, s--, m--;

  int i = e;
  while(i % 28 != s) i += 15;

  int l = lcm(15, 28);
  while(i % 19 != m) i += l;
  cout << i + 1;
}