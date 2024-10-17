#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    ios::sync_with_stdio(0),cin.tie(0);
    set<int> s;
    for(int n : nums)
        s.insert(n);
    return s.size() > nums.size() / 2 ? nums.size() / 2 : s.size();
}