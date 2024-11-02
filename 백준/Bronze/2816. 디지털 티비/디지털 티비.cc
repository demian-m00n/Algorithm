#include <bits/stdc++.h>
using namespace std;

string l[100];
string ans;
int n;
const string KBS1 = "KBS1";
const string KBS2 = "KBS2";

void findKBS1(){
  int cur = 0;
  for( ; l[cur] != KBS1 ; ++cur)
    ans += '1';
  for( ; cur > 0 ; --cur){
    swap(l[cur], l[cur - 1]);
    ans += '4';
  }
}

void findKBS2(){
  int cur = 0;
  for( ; l[cur] != KBS2 ; ++cur)
    ans += '1';
  for( ; cur > 1 ; --cur){
    swap(l[cur], l[cur - 1]);
    ans += '4';
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  
  for(int i = 0 ; i < n ; ++i)
    cin >> l[i];

  findKBS1();
  findKBS2();
  cout << ans;

  return 0;
}