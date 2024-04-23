#include<bits/stdc++.h>
using namespace std;

int n;
int a[100002];
bool used[100002];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> n;

  for(int i = 0 ; i < n ; ++i) cin >> a[i];

  long long ans = 0, cnt = 0, st = 0, en = 0;

  while(1){
    if(!used[a[en]]){
      ++cnt;
      ans += cnt;
      used[a[en]] = true;
      ++en;
    } else {
      --cnt;
      used[a[st]] = false;
      ++st;
    }
    if(en == n) break;
  }

  cout << ans;
  
}