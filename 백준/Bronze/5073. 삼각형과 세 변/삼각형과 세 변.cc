#include <bits/stdc++.h>
using namespace std;

int l[3];

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while(1){
    cin >> l[0] >> l[1] >> l[2];
    sort(l, l + 3);

    if(l[0] + l[1] + l[2] == 0)
      break;

    if(l[2] >= l[0] + l[1])
      cout << "Invalid\n";
    else if(l[2] == l[0])
      cout << "Equilateral\n";
    else if(l[2] == l[1] || l[1] == l[0])
      cout << "Isosceles\n";
    else
      cout << "Scalene\n";
  }

  return 0;
}