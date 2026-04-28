#include <bits/stdc++.h>
using namespace std;

bool func(){
    long long ans;
    long long a,b,c;
    char d,e;
    cin >> a >> d >> b >> e >> c;
    if(d == '+') ans = a+b;
    else if(d == '-') ans = a-b;
    else if(d == '*') ans = a*b;
    else if(d == '/') ans = a/b;
    return ans == c;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    long long t; cin >> t;
    while(t--){
        if(func()) cout << "correct\n";
        else cout << "wrong answer\n";
    }
    
    return 0;
}