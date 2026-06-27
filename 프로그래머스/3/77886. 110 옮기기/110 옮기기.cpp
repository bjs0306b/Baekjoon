#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

string make_min(string s){
    deque<char> dq;
    int cnt = 0;
    int last_zero_idx = -1;
    for(auto k : s){
        if(k == '0' && dq.size() > 1 && dq[dq.size()-2] == '1' && dq[dq.size() - 1] == '1'){
            dq.pop_back();
            dq.pop_back();
            cnt++;
            continue;
        }
        if(k == '0') last_zero_idx = dq.size();
        dq.push_back(k);
    }
    string ret = "";
    if(last_zero_idx == -1) while(cnt--) ret += "110";
    for(int i=0;i<dq.size();i++){  
        ret += dq[i];
        if(i == last_zero_idx){
            while(cnt--) ret += "110";
        }
    }
    return ret;
}

vector<string> solution(vector<string> s) {
    
    vector<string> ret;
    for(auto k : s){
        ret.push_back(make_min(k));
    }
    return ret;
    
}