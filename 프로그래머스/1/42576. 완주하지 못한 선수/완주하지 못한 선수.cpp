#include<bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    
    for(string s : participant) {
        if(m.find(s) != m.end())
            m[s] += 1;
        else
            m[s] = 1;
    }
    
    for(string s : completion) {
            m[s]-= 1;
    }
    
    for(auto e : m)
        if(e.second == 1)
            return e.first;
    
}