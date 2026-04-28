#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; getline(cin, s);
    int happy = 0, sad = 0;
    for(int i=0;i<s.size()-2;i++){
        if(s[i] == ':'){
            if(s[i+1] == '-' && s[i+2] == '(') sad++;
            else if(s[i+1] == '-' && s[i+2] == ')') happy++;
        }
    }
    if(happy == sad){
        if(happy) cout << "unsure";
        else cout << "none";
    }
    else if(happy > sad) cout << "happy";
    else cout << "sad";
    
    return 0;
}