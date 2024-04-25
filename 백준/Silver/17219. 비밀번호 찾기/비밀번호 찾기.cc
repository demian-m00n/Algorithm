#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n, m;
  string url, password;
  cin >> n >> m;
  unordered_map<string,string> record{};
  for(int i = 0 ; i < n ; ++i){
    cin >> url >> password;
    record[url] = password;
  }

  for(int i = 0 ; i < m ; ++i){
    cin >> url;
    cout << record[url] << '\n';
  }

}