#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b;cin>>a>>b;
    map<string, string> m;
    for(int i=0;i<a;i++){string s1,s2; cin >> s1>>s2; m.insert({s1,s2});}
    for(int i=0;i<b;i++){string s3; cin >> s3; cout << m[s3] << "\n";}
    
    
    return 0;
}