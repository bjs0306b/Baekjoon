#include <bits/stdc++.h>
using namespace std;

bool test(string s){
    vector<int> A(26, 0);
    int size = s.size();
    for(int i=0;i<size;i++){
        if(++A[s[i]-'A'] % 3 == 0){
            i++;
            if(i >= size || s[i] != s[i-1]) return false;
        }
    }
    return true;
}

int main(){
    int n; cin >> n;
    while(n--){
        string m; cin >> m;
        if(test(m)) cout << "OK\n";
        else cout << "FAKE\n";
    }
    return 0;
}