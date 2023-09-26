#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n , k;
pair<int,int> jwl[300003];
multiset<int> bag;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> k;
  for(int i=0;i<n;++i)
    cin >> jwl[i].Y >> jwl[i].X ;
  sort(jwl,jwl+n);

  for(int i=0;i<k;++i){
    int c;
    cin >> c;
    bag.insert(c);
  }

  long long ans = 0;

  for(int i= n-1 ; i >= 0 ; --i){
    int m, v;
    tie(v,m)=jwl[i];
    auto it = bag.lower_bound(m);
    if(it == bag.end()) continue;
    ans += v;
    bag.erase(it);
  }

  cout << ans ;
}
