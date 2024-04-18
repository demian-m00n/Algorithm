#include<bits/stdc++.h>
using namespace std;

int fight(int x){
  if(x % 2 == 0) return x/2;
  else return x/2 + 1;
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  int n, x, y;
  cin >> n >> x >> y;
  int a = min(x,y);
  int b = max(x,y);

  int cnt = 1;

  while( a % 2 == 0 || a + 1 != b){
    a = fight(a);
    b = fight(b);
    ++cnt;
  }

  cout << cnt;

}