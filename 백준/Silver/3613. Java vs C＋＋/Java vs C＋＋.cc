#include <bits/stdc++.h>
using namespace std;

bool check_cpp(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] >= 'A' && s[i] <= 'Z') return 0;
    }
    for(int i=1;i<s.size();i++){
        if(s[i] == '_' && s[i-1] == '_') return 0;
    }
    
    if(s[s.size()-1] == '_' || s[0] == '_') return 0;
    return 1;
}

bool check_java(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] == '_') return 0;
    }
    if(s[0] >= 'A' && s[0] <= 'Z') return 0;
    return 1;
}

string cpp_to_java(string s){
    string ret = "";
    ret.push_back(s[0]);
    for(int i=1;i<s.size();i++){
        if(s[i] == '_' && (i != s.size()-1)){
            i++;
            ret.push_back(toupper(s[i]));
        }
        else ret.push_back(s[i]);
    }
    return ret;
}

string java_to_cpp(string s){
    string ret = "";
    for(int i=0;i<s.size();i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
           ret.push_back('_');
            ret.push_back(tolower(s[i]));
        }
        else ret.push_back(s[i]);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;

    if(check_cpp(s)){
        if(check_java(s)){
            cout << s;
        }
        else{
            cout << cpp_to_java(s);
        }
    }
    else{
        if(check_java(s)){
            cout << java_to_cpp(s);
        }
        else{
            cout << "Error!";
        }
    }

    return 0;
}