#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[5005];

ll ans[3] = {0x7f7f7f7f, 0x7f7f7f7f, 0x7f7f7f7f};

int main(void) {
  ios::sync_with_stdio(0),cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);

  for(int i = 0 ; i < n ; ++i){
    for(int j = i + 1 ; j < n ; ++j){
      int idx = lower_bound(a, a + n, -a[i] -a[j]) - a;

      for(int k = -2 ; k <= 2 ; ++k){
        if(idx + k == i || idx + k == j) continue;
        if(idx + k < 0 || idx + k >= n) continue;
        if(abs(ans[0] + ans[1] + ans[2]) > abs(a[i] + a[j] + a[idx + k]))
          tie(ans[0] , ans[1], ans[2]) = {a[i] , a[j] , a[idx + k]};
      }
    }
  }

  sort(ans, ans + 3);

  cout << ans[0] << " " << ans[1] << " " << ans[2];
}