#include <bits/stdc++.h>
using namespace std;

bool is_correct(string s){
    int i = 0;
    if(s[i] == 'A'){
        i = 1;
    }else{
        if(s[1] == 'A'){
            i = 2;
        }
        else return false;
    }

    while(s[i] == 'A') i++;

    if(s[i] != 'F') return false;

    while(s[i] == 'F') i++;

    if(s[i] != 'C') return false;

    while(s[i] == 'C') i++;

    if(s.size() == i) return true;
    if(s.size() == i+1 && s[i] >= 'A' && s[i] <= 'F') return true;
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        if(is_correct(s)) cout << "Infected!\n";
        else cout << "Good\n";
    }

    return 0;
}