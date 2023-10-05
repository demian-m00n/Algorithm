#include<bits/stdc++.h>
using namespace std;
int n,top = 0;
vector<int> v;
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;
  while(n--){
    string s;
    int i;
    cin >> s;
    if(s.compare("push")==0){
      cin >> i;
      v.push_back(i);
      ++top;
    }
    else if(s.compare("pop")==0){
      if(top == 0) cout << -1 << '\n';
      else{
        cout << v[top-1] << '\n';
        v.pop_back();
        --top;
      }
    }
    else if(s.compare("size")==0){
      cout << top << '\n';
    }
    else if(s.compare("empty")==0){
      if(top == 0) cout << 1 << '\n';
      else cout << 0 << '\n';
    }
    else if(s.compare("top")==0){
      if(top == 0) cout << -1 << '\n';
      else cout << v[top-1] << '\n';
    }
  }
}