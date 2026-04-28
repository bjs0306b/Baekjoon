#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

bool good_word(string s) {
    vector<char> v;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        char c = *iter;
        if (!v.empty() && v.back() == c)
            v.pop_back();
        else
            v.push_back(c);
    }
    return v.empty();
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    while(n--){
        string str; cin >> str;
        if(good_word(str)) cnt++;
    }
    cout << cnt;
    
    return 0;
}