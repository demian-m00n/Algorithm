#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  int len = 1, exp = 1;
  while (k > 9LL * len * exp) {
    k -= 9LL * len * exp;
    exp *= 10;
    len++;
  }
  int target = exp + (k - 1) / len;
  if (target > n) cout << -1;
  else cout << to_string(target)[(k - 1) % len];
}