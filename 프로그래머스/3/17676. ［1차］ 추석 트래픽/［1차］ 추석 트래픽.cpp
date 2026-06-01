#include <string>
#include <vector>
#include <iostream>

using namespace std;

pair<long long, long long> to_ms(string str){
    // int Y = stoi(str.substr(0, 4));
    // int M = stoi(str.substr(5, 2));
    // int D = stoi(str.substr(8, 2));
    int h = stoi(str.substr(11, 2));
    int m = stoi(str.substr(14, 2));
    int s = stoi(str.substr(17, 2));
    string temp = "";
    int i;
    for(i=20;;i++){
        if(str[i] == ' ') break;
        temp += str[i];
    }
    int ms = stoi(temp);
    temp = "";
    i++;
    string dif_s = "", dif_ms = "0";
    for(;;i++){
        if(str[i] == '.' || str[i] == 's') break;
        dif_s += str[i];
    }
    i++;
    for(;i<str.size();i++){
        if(str[i] == 's') break;
        dif_ms += str[i];
    }
    while(dif_ms.size() <= 3){
        dif_ms += '0';
    }
    long long ret2 = stoi(dif_s) * 1000 + stoi(dif_ms);
    
    
    long long ret1 = ms + 1000*s + 1000*60*m + 1000*60*60*h;

    return {ret1 - ret2 + 1 , ret1};
}

int solution(vector<string> lines) {
    vector<pair<long long, long long>> ms;
    for(auto k : lines){
        auto temp = to_ms(k);
        ms.push_back(temp);
    }
    
    int ans = 0;
    for(int i=0;i<ms.size();i++){
        long long s = ms[i].first, e = s + 999;
        int cnt = 0;
        for(int j=0;j<ms.size();j++){
            if(e < ms[j].first || ms[j].second < s) continue;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    
    for(int i=0;i<ms.size();i++){
        long long s = ms[i].second, e = s + 999;
        int cnt = 0;
        for(int j=0;j<ms.size();j++){
            if(e < ms[j].first || ms[j].second < s) continue;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    
    return ans;
}