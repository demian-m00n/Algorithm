#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int b, c;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 1 ; i <= n ; ++i){
    cin >> a[i];
  }

  cin >> b >> c;

  long long result = 0;

  for(int i = 1 ; i <= n ; ++i){
    a[i] -= b;
    result += 1;
    if(a[i] > 0){
      result += (a[i] + c - 1) / c;
    }
  }

  cout << result;

  return 0;
}