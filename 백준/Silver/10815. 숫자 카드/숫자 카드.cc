#include<bits/stdc++.h>
using namespace std;

vector<int> v;

bool bs(int t, int start, int end){
  if(start > end) return false;
  int mid = (start + end) / 2;
  if(v[mid] == t) return true;
  else if(v[mid] > t) return bs(t,start,mid - 1);
  else if(v[mid] < t) return bs(t,mid + 1, end);
  return false;
};

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int n, m;
  cin >> n;

  for(int i = 0 ; i < n ; ++i){
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(),v.end());

  cin >> m;

  while (m--)
  {
    int x;
    cin >> x;
    if(bs(x,0,n-1)) cout << 1 << ' ';
    else cout << 0 << ' ';
  }
  
}