#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int power_two[6] = {1,3,7,15,31,63};
bool makable;

string to_bi(long long num){
    string ret = "";
    while(num){
        int temp = num % 2;
        num /= 2;
        ret += (temp + '0');
    }
    reverse(ret.begin(), ret.end());
    
    int size = ret.size();
    auto iter = lower_bound(power_two, power_two + 6, size);
    int idx = iter - power_two;
    int target = power_two[idx];
    int dif = target - size;
    string zeros = string(dif, '0');
    return zeros + ret;
}

void can_make(int s, int e, string str){
    if(makable == false) return;
    if(s == e) return;
    
    int m = (s + e) / 2;
    if(str[m] == '0' && (str[(s + m - 1) / 2] == '1' || str[(m + 1 + e) / 2] == '1')) makable = false;
    can_make(s, m-1, str);
    can_make(m+1, e, str);
}

bool check(long long num){
    string s = to_bi(num); 
    int size = s.size();
    
    makable = true;
    can_make(0, size-1, s);
    
    return makable;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    
    
    for(auto k : numbers){
        if(check(k)) answer.push_back(1);
        else answer.push_back(0);
    }
    
    return answer;
}