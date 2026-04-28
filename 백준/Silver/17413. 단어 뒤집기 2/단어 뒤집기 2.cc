#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; getline(cin, s);
    vector<char> v;
    for(int i=0;i<s.size();i++){
        if(s[i] == '<'){
            while(!v.empty()){cout << v.back(); v.pop_back();}
            while(s[i] != '>') cout << s[i++]; cout << ">";
        }
        else if(s[i] == ' '){
            while(!v.empty()){cout << v.back(); v.pop_back();}
            cout << " ";
        }
        else{
            v.push_back(s[i]);
        }
    }
    while(!v.empty()){cout << v.back(); v.pop_back();}
    
    
    return 0;
}