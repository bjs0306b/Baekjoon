#include <bits/stdc++.h>
using namespace std;

long long ans(){
    string s; cin >> s;
    stack<char> st;
    long long ret = 0;
    long long temp = 1;
    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(c == '['){
            temp *= 3;
            st.push('[');
        }
        else if(c == '('){
            temp *= 2;
            st.push('(');
        }
        else if(c == ']'){
            if(st.empty() || st.top() != '[') return 0;
            if(s[i-1] == '[') ret += temp;
            temp /= 3;
            st.pop();
        }
        else if(c == ')'){
            if(st.empty() || st.top() != '(') return 0;
            if(s[i-1] == '(') ret += temp;
            temp /= 2;
            st.pop();
        }
    }
    if(!st.empty()) return 0;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << ans();
    return 0;
}