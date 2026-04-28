#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    string s[n];
    for(int i=0;i<n;i++) getline(cin, s[i]);
    for(int i=0;i<n;i++) cout << i+1 << ". " << s[i] << "\n";
    
    return 0;
}