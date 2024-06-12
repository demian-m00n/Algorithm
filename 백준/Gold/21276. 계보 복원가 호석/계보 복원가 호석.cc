#include<bits/stdc++.h>
using namespace std;

int N, M;
string child, parent;
string name[1002];
unordered_map<string,int> person;
int indeg[1002];
vector<int> adj[1002];
vector<int> ch[1002];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N;

  for(int i = 1 ; i <= N ; ++i)
    cin >> name[i];
  sort(name + 1, name + N + 1);

  for(int i = 1; i <= N ; ++i)
    person[name[i]] = i;

  cin >> M;

  for(int i = 0 ; i < M ; ++i){
    cin >> child >> parent;
    indeg[person[child]]++;
    adj[person[parent]].push_back(person[child]);
  }

  vector<int> ac;
  for(int i = 1 ; i <= N ; ++i)
    if(!indeg[i]) ac.push_back(i);

  cout << ac.size() << '\n';
  for(int a : ac)
    cout << name[a] << ' ';
  cout << '\n';

  for(int i = 1 ; i <= N ; ++i){
    sort(adj[i].begin(), adj[i].end());
    for(int c : adj[i])
      if(indeg[c] - indeg[i] == 1) ch[i].push_back(c);
  }
  
  for(int i = 1 ; i <= N ; ++i){
    int sz = ch[i].size();
    cout << name[i] << ' ' << sz << ' ';
    for(int c : ch[i])
      cout << name[c] << ' ';
    cout << '\n';
  }
  
}