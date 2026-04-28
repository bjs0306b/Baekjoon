#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0;j<s.size();j++) s[j] = tolower(s[j]);
        cout << s << "\n";
    }
    
    
    return 0;
}