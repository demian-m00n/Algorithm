#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll a[100005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;
  for(int i = 0 ; i < n ; ++i)
    cin >> a[i];
  sort(a, a+n);
  int cnt = 0;
  ll mxval = -(1ll << 62) - 1;
  int mxcnt = 0;
  for(int i = 0 ; i < n ; ++i){
    if(i == 0 || a[i-1] == a[i]) cnt++;
    else{
      if(cnt > mxcnt){
        mxcnt = cnt;
        mxval = a[i-1];
      }
      cnt = 1;
    }
  }
  if(cnt > mxcnt) mxval = a[n-1];
  cout << mxval;
}