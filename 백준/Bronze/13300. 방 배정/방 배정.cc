#include<bits/stdc++.h>
using namespace std;

int n , k ;
int stu[2][7];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n >> k ;

  while(n--){
    int s , y ;
    cin >> s >> y ;
    ++stu[s][y];
  }

  int room = 0 ;

  for(int i = 0 ; i < 2 ; ++i){
    for(int j = 1 ; j < 7 ; ++j){
      room += stu[i][j] / k ;
      if(stu[i][j] % k != 0) ++room ;
    }
  }

  cout << room ;
}