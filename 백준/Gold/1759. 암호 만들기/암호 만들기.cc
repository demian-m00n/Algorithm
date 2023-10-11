#include<bits/stdc++.h>
using namespace std;

int l, c;
char input[16];
bool mask[16];

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> l >> c ;

  for(int i = 0 ; i < c ; ++i)
    cin >> input[i];
  
  sort(input,input + c);

  for(int i = l ; i < c ; ++i)
    mask[i] = 1 ;

  do{
    int cnt = 0;
    for(int i = 0 ; i < c ; ++i){
      if(!mask[i]){
        for(char x : {'a', 'e', 'i', 'o', 'u'}){
          if(input[i] == x){
            ++cnt;
          }
        }
      }
    }

    if(cnt < 1 || l - cnt < 2) continue;
    for(int i = 0 ; i < c ; ++i){
      if(!mask[i])
        cout << input[i];
    }
    cout << '\n';
  }while(next_permutation(mask,mask + c));

}