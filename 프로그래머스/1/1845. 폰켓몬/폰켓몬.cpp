#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    ios::sync_with_stdio(0),cin.tie(0);
    unordered_set<int> s(nums.begin(), nums.end());
    return min(nums.size() / 2, s.size());
}