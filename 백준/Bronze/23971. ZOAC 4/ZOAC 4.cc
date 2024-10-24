#include <bits/stdc++.h>
using namespace std;

int w, h, n, m;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> w >> h >> n >> m;

  cout << ((w + n) / (n + 1)) * ((h + m ) / (m + 1));

  return 0;
}