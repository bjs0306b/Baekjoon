#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

vector<string> vec[8];

char func(string s){
    for(int i=0;i<8;i++){
        for(string k : vec[i]){
            if(s == k) return i + 'A';
        }
    }
    return 'I';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    string ss[8] = {"000000","001111","010011","011100", "100110","101001","110101" ,"111010"};
    for(int j=0;j<8;j++){
        string aa= ss[j];
        vec[j].push_back(aa);
        for(int i=0;i<6;i++){
            string temp = aa;
            if(temp[i] == '0') temp[i] = '1';
            else temp[i] = '0';
            vec[j].push_back(temp);
        }
    }
    string ans = "";
    for(int i=0;i<n;i++){
        string temp = s.substr(i*6, 6);
        char ch = func(temp);
        if(ch == 'I'){cout << i+1; return 0;}
        else ans += ch;
    }
    cout << ans;
    
    return 0;
}