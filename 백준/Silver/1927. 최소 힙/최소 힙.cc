#include<bits/stdc++.h>
using namespace std;

int n, a;

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> n;

  priority_queue<unsigned int, vector<unsigned int>, greater<>> pq;

  while(n--){
    cin >> a;
    if(a == 0){
      if(pq.empty()) cout << 0 <<'\n';
      else{
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
    else{
      pq.push(a);
    }
  }
}