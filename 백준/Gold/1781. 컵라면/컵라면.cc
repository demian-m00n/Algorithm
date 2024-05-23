#include<bits/stdc++.h>
using namespace std;

int N, dl, cr;
unsigned int cupNoodles = 0;
priority_queue<unsigned int> cr_candidate;
vector<vector<unsigned int>> cr_by_dl(200002);

int main(void){
  ios::sync_with_stdio(0),cin.tie(0);

  cin >> N;
  for(int i = 0 ; i < N ; ++i){
    cin >> dl >> cr;
    cr_by_dl[dl].push_back(cr);
  }
  for(int curr = 200'001; curr != 0 ; --curr){
    for(int cup : cr_by_dl[curr])
      cr_candidate.push(cup);

    if(cr_candidate.empty()) continue;
    cupNoodles += cr_candidate.top();
    cr_candidate.pop();
  }

  cout << cupNoodles;
}