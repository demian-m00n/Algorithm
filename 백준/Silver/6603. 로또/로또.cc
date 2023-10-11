#include<bits/stdc++.h>
using namespace std;

int arr[6];
int num[14];

int k;

void func(int cur, int x){
  if(x == 6){
    for(int i = 0 ; i < 6 ; ++i)
      cout << arr[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i = cur ; i < k ; ++i){
    arr[x] = num[i];
    func(i + 1, x + 1);
  }
}

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  while(true){
    cin >> k;
    if(k == 0){
      break;
    }

    for(int i = 0 ; i < k ; ++i)
      cin >> num[i];

    sort(num,num+k);
    func(0,0);

    cout << '\n';
  }
}