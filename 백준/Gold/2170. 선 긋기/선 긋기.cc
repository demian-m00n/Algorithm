#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int,int>> events;  
  int n;
  cin >> n;
  while(n--){
    int l, r;
    cin >> l >> r;
    events.push_back({l, 1});
    events.push_back({r, -1});
  }
  sort(events.begin(), events.end());
  int cnt = 0; 
  int tot = 0; 
  int loc = -1e9;
  for(auto event : events){
    if(cnt > 0) tot += (event.X - loc);
    loc = event.X;
    cnt += event.Y;
  }
  cout << tot;
}