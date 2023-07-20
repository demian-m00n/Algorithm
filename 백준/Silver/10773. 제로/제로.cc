#include<bits/stdc++.h>
using namespace std;
int n;
stack<int> st;
int main(void){
  ios::sync_with_stdio(0),cin.tie(0);
  cin >> n;
  while(n--){
    int i;
    cin >> i;
    if(i==0) st.pop();
    else st.push(i);
  }
  int sum = 0;
  while(!st.empty()){
    sum += st.top();
    st.pop();
  }

  cout << sum ;

}