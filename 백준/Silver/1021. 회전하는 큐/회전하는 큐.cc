#include<bits/stdc++.h>
using namespace std;
deque<int> dQ;
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n , m , ans = 0;
  cin >> n;
  for(int i = 1 ; i<=n ; ++i){
    dQ.push_back(i);
  }

  cin >> m;
  while(m--){
    int a;
    cin >> a;
    int idx = find(dQ.begin(),dQ.end(), a) - dQ.begin();
    while(dQ.front()!=a){
      if(idx < dQ.size() - idx){
        dQ.push_back(dQ.front());
        dQ.pop_front();
      }
      else{
        dQ.push_front(dQ.back());
        dQ.pop_back();
      }
      ans ++ ;
    }
    dQ.pop_front();
  }
  cout << ans ;
}