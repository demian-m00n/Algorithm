#include<bits/stdc++.h>
using namespace std;

int t;
int d[10005];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> t;
  while(t--){
    fill(d,d+10005,0);

    int n, m;
    cin >> n;
    vector<int> coin(n);

    for(int i = 0 ; i < n ; ++i)
      cin >> coin[i];
    
    cin >> m;
    d[0] = 1;
    for(int i = 0 ; i < n ; ++i)
      for(int j = coin[i] ; j <= m ; ++j)
        d[j] += d[j - coin[i]];

    cout << d[m] << '\n';
  }
}