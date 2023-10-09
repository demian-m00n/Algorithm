#include<bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
int building[1000002];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> f >> s >> g >> u >> d;

  fill(building,building+f+1,-1);
  building[s] = 0;
  queue<int> Q;
  Q.push(s);
  while(!Q.empty()){
    int cur = Q.front(); Q.pop();
    for(int x : {u,-d}){
      int nxt = cur + x;
      if(nxt < 1 || nxt > f)
        continue;
      if(building[nxt] != -1)
        continue;
      building[nxt] = building[cur] + 1;
      Q.push(nxt);
    }
  }

  if(building[g] == -1) cout << "use the stairs";
  else cout << building[g];
  
}