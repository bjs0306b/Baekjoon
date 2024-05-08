#include<bits/stdc++.h>
using namespace std;

int gcb(int a, int b){
    if(a%b==0) return b;
    return gcb(b, a%b);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; cin >> a >> b;
    int la = a.size(), lb = b.size();
    if(la > lb) swap(a,b), swap(la,lb);
    int c = gcb(la, lb);
    
    string s1 = "", s2 = "";

    for(int i=0;i<lb/c;i++) s1 += a;
    for(int i=0;i<la/c;i++) s2 += b;

    if(s1 == s2) cout << 1;
    else cout << 0;
    
    return 0;
}