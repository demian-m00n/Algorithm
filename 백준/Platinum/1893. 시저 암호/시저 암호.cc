#include <bits/stdc++.h>
using namespace std;

vector<int> f, ans;
string a, w, s;
int cnt[64];
int oa[257], ma[257];

vector<int> failure(){
  vector<int> f(w.size());
  int j = 0;
  for(int i = 1; i < w.size(); i++){
    while(j > 0 && w[i] != w[j]) j = f[j-1];
    if(w[i] == w[j]) f[i] = ++j;
  }
  return f;
}

void solve(){
  int as = a.size();
  for(int k = 0; k < as; k++){
    for(int i = 0; i < as; i++)
      ma[a[i]] = (oa[a[i]] + k)%as;

    int j = 0;
    for(int i = 0; i < s.size(); i++){
      while(j > 0 && oa[s[i]] != ma[w[j]]) j = f[j-1];
      if(oa[s[i]] == ma[w[j]]) j++;
      if(j == w.size()){
        j = f[j-1];
        cnt[k]++;
      }
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--){
    vector<int> ().swap(f);
    vector<int> ().swap(ans);
    fill(cnt, cnt + 64, 0);

    cin >> a >> w >> s;
    for(int i = 0; i < a.size(); i++) oa[a[i]] = i;

    f = failure();
    solve();

    for(int k = 0; k < a.size(); k++)
      if(cnt[k] == 1) ans.push_back(k);

    if(ans.size() == 0) cout << "no solution\n";
    else if(ans.size() == 1)
      cout << "unique: " << ans[0] << '\n';
    else {
      cout << "ambiguous: ";
      for(int a : ans) cout << a << ' ';
      cout << '\n';
    }
  }
}