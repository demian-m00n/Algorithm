#include<bits/stdc++.h>
using namespace std;

int a[1005];
int n;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;

  for(int i = 1 ; i <= n ; ++i)
    cin >> a[i];

  int ans = 0;
  int t = 0;

  sort(a + 1, a + n +1);

  for(int i = 1 ; i <= n ; ++i){
    t += a[i];
    ans += t;
  }

  cout << ans;
}