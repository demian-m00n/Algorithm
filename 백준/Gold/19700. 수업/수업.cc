#include<bits/stdc++.h>
using namespace std;

int N;
pair<int, int> a[500005];


int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> a[i].first >> a[i].second;

  sort(a, a + N, greater<pair<int, int>>());

  multiset<int> s;

  for (int i = 0; i < N; i++) {
    auto it = s.lower_bound(-a[i].second + 1);
    if (it == s.end()) s.insert(-1);
    else {
      int val = *it;

      s.erase(it);
      s.insert(val - 1);
    }
  }

  cout << s.size();
}