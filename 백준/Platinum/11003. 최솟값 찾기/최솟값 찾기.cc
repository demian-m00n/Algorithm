#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n , l ;
  deque<pair<int,int>> dQ;
  cin >> n >> l ;

  for(int i=0;i<n;++i){
    int a;
    cin >> a;
    while(!dQ.empty() && dQ.back().second >= a){
      dQ.pop_back();
    }
    dQ.push_back({i,a});
    
    if(dQ.front().first <= i - l) {
      dQ.pop_front();
    }
    cout << dQ.front().second << ' ';
  }
}