#include<bits/stdc++.h>
using namespace std;

int n ;
int a[1000005];
int ans[1000005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n ;
  for(int i = 0 ; i < n ; ++i) cin >> a[i];
  stack<int> s ;
  int nge = 0 ;
  for(int i = n - 1 ; i >= 0 ; --i){
    while(!s.empty() && a[i] >= s.top()){
      s.pop() ;
    }
    if(s.empty()) ans[i] = -1 ;
    else ans[i] = s.top() ;
    s.push(a[i]) ;
  }

  for(int i = 0 ; i < n ; ++i) cout << ans[i] << ' ' ;
}