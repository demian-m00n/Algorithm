#include<bits/stdc++.h>
using namespace std;

int a[101];
int n;

int main(void){
  cin >> n;

  for(int i = 0 ; i < n ; ++i) cin >> a[i];

  for(int i = 1 ; i < n ; ++i){
    int _gcd = gcd(a[0],a[i]);
    cout << a[0]/_gcd << '/' << a[i]/_gcd << '\n';
  }
}