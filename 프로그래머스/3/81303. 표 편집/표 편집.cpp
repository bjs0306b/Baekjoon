#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
   
    vector<int> next(n), prev(n);
    next[n-1] = n; prev[0] = -1;
    for(int i=0;i<n-1;i++){
        next[i] = i+1;
        prev[i+1] = i;
    }
    
    int cur_pos = k;
    stack<int> delete_his;
    
    for(auto s : cmd){
        if(s[0] == 'U'){
            int num = stoi(s.substr(2));
            while(num--){
                cur_pos = prev[cur_pos];
            }
        }else if(s[0] == 'D'){
            int num = stoi(s.substr(2));
            while(num--){
                cur_pos = next[cur_pos];
            }
        }else if(s[0] == 'C'){
            delete_his.push(cur_pos);
            if(next[cur_pos] == n) // 마지막 행인 경우
            {
                next[prev[cur_pos]] = n;
                cur_pos = prev[cur_pos];
            }
            else if(prev[cur_pos] == -1){
                prev[next[cur_pos]] = -1;
                cur_pos = next[cur_pos];
            }
            else{
                next[prev[cur_pos]] = next[cur_pos];
                prev[next[cur_pos]] = prev[cur_pos];
                cur_pos = next[cur_pos];
            }
            
        }else if(s[0] == 'Z'){
            int t = delete_his.top();
            delete_his.pop();
            if(prev[t] != -1) next[prev[t]] = t;
            if(next[t] != n) prev[next[t]] = t;
        }
    }
    
    string ret = string(n, 'X');
    
    ret[cur_pos] = 'O';
    int temp = cur_pos;
    while(true){
        temp = prev[temp];
        if(temp == -1) break;
        ret[temp] = 'O';
    }
    temp = cur_pos;
    while(true){
        temp = next[temp];
        if(temp == n) break;
        ret[temp] = 'O';
    }
    
    return ret;
}