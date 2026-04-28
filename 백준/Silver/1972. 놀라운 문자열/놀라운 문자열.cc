#include <bits/stdc++.h>
using namespace std;

bool func(string s){

    for(int i=1;i<s.size()-1;i++){
        set<string> st;
        for(int j=0;j<s.size()-i;j++){
            string temp = "";
            temp += s[j];
            temp += s[j+i];
            // cout << temp << " ";
            if(st.find(temp) != st.end()) return false;
            st.insert(temp); 
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(;;){
        string s; cin >> s;
        if(s == "*") break;
        
        if(func(s)) cout << s << " is surprising.\n";
        else cout << s << " is NOT surprising.\n";
    }

    return 0;
}