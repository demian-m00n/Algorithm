#include<bits/stdc++.h>
using namespace std;
string s;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> s;
  list<char> L;
  for(auto c : s) L.push_back(c);
  auto cursor = L.end();
  int q;
  cin >> q;
  while(q--){
    char op;
    cin >> op;
    if(op == 'P'){
      char add;
      cin >> add;
      L.insert(cursor,add);
    }
    else if(op=='L'){
      if(cursor != L.begin()) cursor--;
    }
    else if(op=='D'){
      if(cursor != L.end()) cursor ++;
    }
    else{ //B
      if(cursor != L.begin()){
        cursor--;
        cursor = L.erase(cursor);
      }
    }
  }
  for (auto c : L) cout << c;
}