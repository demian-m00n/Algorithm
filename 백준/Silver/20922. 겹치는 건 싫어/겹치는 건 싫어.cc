#include<bits/stdc++.h>
using namespace std;

int a[200005], n, k;
int use[100005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> k;
  for(int i = 0 ; i < n ; ++i) cin >> a[i];
  int st = 0, en = 0, ans = 0;

  use[a[st]]++;

  while(1){
    if(use[a[en]] <= k){
      en++;
      use[a[en]]++;
    }
    if(use[a[en]] > k){
      use[a[st]]--;
      st++;
    }
    if(en == n) break;
    ans = max(ans, en - st + 1);
  }

  cout << ans;
}