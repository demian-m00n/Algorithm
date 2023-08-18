#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p[105];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  int t , n ;
  cin >> t;

  p[1] = 1;
  p[2] = 1;
  p[3] = 1;
  p[4] = 2;
  p[5] = 2;

  for(int i = 6 ; i <=100 ; ++i)
    p[i] = p[i-2] + p[i-3];

  for(int i = 0 ; i < t ; ++i){
    cin >> n;
    cout << p[n] << '\n' ;
  }
}