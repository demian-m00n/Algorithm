#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;
  
  while(n--){
    int t;
    cin >> t;
    a.push_back(t);
  }

  sort(a.begin(),a.end());

  for(int x : a){
    cout << x << '\n';
  }

}