#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int cnt = 1;
  int num = 1;

  while(num < n){
    num += cnt++ * 6;
  }

  cout << cnt;

  return 0;
}