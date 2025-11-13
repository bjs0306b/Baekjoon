#include <bits/stdc++.h>
using namespace std;

bool test(string s){
    vector<int> A(26, 0);
    int size = s.size();
    for(int i=0;i<size;i++){
        A[s[i]-'A']++;
        if(A[s[i]-'A'] % 3 == 0){
            if(i+1 >= size || s[i+1] != s[i]) return false;
            i++;
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