#include<bits/stdc++.h>
using namespace std;

int n;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> n;

  int t = 1;
  
  while(1){
    if(n - t <= 0){
      break;
    }
    n -= t;
    ++t;
  }

  ++t;

  if(t % 2 != 0)
    cout << n << '/' << t - n;
  else
    cout << t - n << '/' << n;
}