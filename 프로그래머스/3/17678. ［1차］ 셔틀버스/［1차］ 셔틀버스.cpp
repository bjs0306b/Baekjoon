#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string to_string_time(int n){
    string ret = "";
    string h = to_string(n / 60);
    if(h.size() == 1) ret += '0';
    ret += h;
    ret += ':';
    string m = to_string(n % 60);
    if(m.size() == 1) ret += '0';
    ret += m;
    
    return ret;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> times;
    for(auto k : timetable){
        int h = stoi(k.substr(0,2));
        int m = stoi(k.substr(3,2));
        times.push_back(60*h + m);
    }
    sort(times.begin(), times.end());
    
    int cur_min = 540;
    int cur_idx = 0;
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<m;j++){
            if(cur_idx == times.size()){
                int ret = (n - i - 1) * t + cur_min;
                cout << "1";
                return to_string_time(ret);
            }
            if(cur_min >= times[cur_idx]){
                cur_idx++;
            }
            else break;
        }
        
        if(i == n-1){
            if(j == m){
                cout << "2";
                return to_string_time(times[cur_idx-1] - 1);
            }
            else{
                cout << "3";
                return to_string_time(cur_min);
            }
        }
        
        cur_min += t;
    }
}