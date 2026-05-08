#include <string>
#include <vector>
#include <iostream>

using namespace std;

string to_n(int n, int num){
    string ret = "";
    if(num == 0) return "0";
    vector<int> temp;
    while(num){
        temp.push_back(num % n);
        num /= n;
    }
    for(int i=temp.size()-1;i>=0;i--){
        char c;
        if(temp[i] > 9){
            c = temp[i] - 10 + 'A';
        }
        else c = '0' + temp[i];
        
        ret += c;
    }
    return ret;
}

string solution(int n, int t, int m, int p) {
    int idx = 0, required_length = m*(t-1)+p;
    string s = "";
    while(required_length > 0){
        string temp = to_n(n, idx);
        idx++;
        s += temp;
        required_length -= temp.size();
    }
    string answer = "";
    for(int i=0;i<t;i++){
        answer += s[p-1+i*m];
    }

    
    return answer;
}