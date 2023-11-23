#include<bits/stdc++.h>
using namespace std;

int t;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> t;
  while(t--){
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0 ; i < n ; ++i)
      cin >> a[i];
    for(int i = 0 ; i < m ; ++i)
      cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i = n-1 ; i >= 0 ; --i){
      for(int j = m-1 ; j >= 0 ; --j){
        if(a[i] > b[j]){
          cnt += j + 1;
          break;
        }
      }
    }

    cout << cnt << '\n';
  }
}