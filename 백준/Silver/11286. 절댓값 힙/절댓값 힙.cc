#include<bits/stdc++.h>
using namespace std;

int n;
class cmp {
  public:
    bool operator() (int a, int b){
      if(abs(a) != abs(b)) return abs(a) > abs(b);
      return a > 0 && b < 0 ;
    }
};


int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  priority_queue<int,vector<int>,cmp> pQ;
  cin >> n;
  for(int i = 0 ; i < n ; ++i){
    int x;
    cin >> x;
    if(x) pQ.push(x);
    else{
      if(pQ.empty()) cout << 0 << '\n';
      else{
        cout << pQ.top() << '\n';
        pQ.pop();
      }
    }
  }
}