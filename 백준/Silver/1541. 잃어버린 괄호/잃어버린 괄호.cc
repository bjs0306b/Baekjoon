#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    vector<int> v1;
    vector<char> v2;
    string temp = "0";
    for(int i=0;i<s.size();i++){
        if(s[i] == '+') {v2.push_back('+'); v1.push_back(stoi(temp)); temp = "0";}
        else if(s[i] == '-') {v2.push_back('-'); v1.push_back(stoi(temp)); temp = "0";}
        else temp += s[i];
    }
    v1.push_back(stoi(temp));

    int sum = v1[0];
    int pos = v2.size();
    for(int i=0;i<v2.size();i++) if(v2[i] == '-'){ pos = i; break;}
    for(int i=pos;i<v2.size();i++) v2[i] = '-';
    for(int i=0;i<v2.size();i++){
        int num = v1[i+1];
        if(v2[i] == '+') sum+=num;
        else if(v2[i] == '-') sum-=num;
    }
    cout << sum;
    
    
    return 0;
}