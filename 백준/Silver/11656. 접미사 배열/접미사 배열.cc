#include<bits/stdc++.h>
using namespace std;

string st;
vector<string> v;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> st;
  int len = st.length();

  for(int i = 0 ; i < len ; ++i)
    v.push_back(st.substr(i,len - i));

  sort(v.begin(),v.end());

  for(string str : v)
    cout << str << '\n';
}