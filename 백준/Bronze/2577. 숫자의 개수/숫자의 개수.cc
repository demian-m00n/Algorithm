#include<bits/stdc++.h>
using namespace std;
int arr[10];
int a,b,c,r;
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> a >> b >> c;
  r = a * b * c;
  while(r > 0){
    arr[r%10]++;
    r/=10;
  }
  for(int i : arr)
    cout << i << '\n' ;
}