#include<bits/stdc++.h>
using namespace std;

int sum(int x){
  int i = 1, tot = 0;
  while(x > i){
    x -= i;
    tot += pow(i,2);
    ++i;
  }
  tot += i * x;


  return tot;
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  int a, b;
  cin >> a >> b;
  cout << sum(b) - sum(a-1);
}