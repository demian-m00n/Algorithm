#include<bits/stdc++.h>
using namespace std;

int N, t;
int num[100002];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> N;

  for(int i = 0 ; i < N ; ++i){
    cin >> t;
    num[t]++;
  }

  for(int i = 1 ; i <= 100000 ; ++i){
    while(num[i]){
      cout << i << '\n';
      num[i]--;
    }
  }
}