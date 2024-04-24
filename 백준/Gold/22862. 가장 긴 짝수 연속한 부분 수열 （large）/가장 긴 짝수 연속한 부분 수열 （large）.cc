#include<bits/stdc++.h>
using namespace std;

int n, k, s[1000005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> k;
  
  for(int i = 0 ; i < n ; ++i) cin >> s[i];

  int ans = 0, st = 0, en = 0;

  int cnt = (s[st] % 2);

  while(1){
      ans = max(ans, en - st + 1 - cnt);
    if(cnt <= k){
      en++;
      if(s[en] % 2 != 0)
        cnt++;
    } else {
      if(s[st] % 2 != 0)
        cnt--;
      st++;
    }
    if(en == n) break;
  }

  cout << ans;
}