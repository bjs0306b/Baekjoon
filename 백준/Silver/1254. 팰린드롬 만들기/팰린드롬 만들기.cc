#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s){
    auto iter1 = s.begin(), iter2 = --s.end();
    while(iter1 < iter2){
        if(*iter1++ != *iter2--) return false;
        
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    for(int i=0;i<s.size();i++){
        if(is_palindrome(s.substr(i, s.size()-i))){
            cout << s.size() + i;
            break;
        }
    }

    return 0;
}