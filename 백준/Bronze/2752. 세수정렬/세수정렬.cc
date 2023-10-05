#include<bits/stdc++.h>
using namespace std;
int a[3];
int main(){
  cin >> a[0] >> a[1] >> a[2];
  int mx = max(max(a[0],a[1]),a[2]);
  int mn = min(min(a[0],a[1]),a[2]);
  cout << mn << ' ';
  for(int i : a){
    if(i!=mx&&i!=mn) cout << i << ' ';
  }
  cout << mx << ' ';
}