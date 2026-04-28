#include <bits/stdc++.h>
using namespace std;

int palindrome(string s, int i, int j, bool flag){
    while(i <= j){
        if(s[i] != s[j]){
            if(!flag) return 2;
            flag = false;

            int temp1 = palindrome(s, i+1, j, flag);
            int temp2 = palindrome(s, i, j-1, flag);

            return min(temp1, temp2);
        }
        i++, j--;
    }
    if(flag) return 0;
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        cout << palindrome(s, 0, s.size()-1, true) << "\n";
    }

    return 0;
}