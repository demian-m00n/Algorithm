#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int k, l;
  cin >> k >> l;
  unordered_map<string, int> signup{};
  for(int i = 0 ; i < l ; ++i){
    string st_num;
    cin >> st_num;
    if(signup.find(st_num) != signup.end()){
      signup.erase(st_num);
      signup[st_num] = i;
    }
    else
      signup[st_num] = i;
  }

  vector<pair<string,int>> slist(signup.begin(),signup.end());
  sort(slist.begin(),slist.end(),[](auto& a, auto& b) { return a.Y < b.Y;});

  int en = min(k, (int)slist.size());

  for(int i = 0 ; i < en ; ++i)
    cout << slist[i].X << '\n';
}