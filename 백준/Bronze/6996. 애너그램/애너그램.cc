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
        string a,b; cin>>a>>b;
        string aa=a,bb=b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout << aa << " & " << bb;
        if(a==b) cout << " are anagrams.";
        else cout << " are NOT anagrams.";
        cout << "\n";
    }
    
    return 0;
}