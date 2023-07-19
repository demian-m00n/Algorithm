#include<bits/stdc++.h>
using namespace std;
int i;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> i;
  if(i>=90) cout << 'A';
  else if(i>=80) cout<< 'B';
  else if(i>=70) cout<< 'C';
  else if(i>=60) cout<< 'D';
  else cout<<'F';
  return 0;
}