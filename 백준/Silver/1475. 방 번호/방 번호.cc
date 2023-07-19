#include<bits/stdc++.h>
using namespace std;
int n;
int a[10];
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n ;
  while(n > 0){
    a[n%10]++;
    n/=10;
  }
  a[9] = a[6] + a[9];
  a[6] = a[9]/2;
  a[9] -= a[6];
  int mx = 0;
  for(int i : a ) mx = max(mx,i);
  cout << mx ;
}