#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; cin >>a>>b;
    int h1,h2,m1,m2,s1,s2,h3,m3,s3;
    h1 = stoi(a.substr(0,2)); h2 = stoi(b.substr(0,2));
    m1 = stoi(a.substr(3,2)); m2 = stoi(b.substr(3,2));
    s1 = stoi(a.substr(6,2)); s2 = stoi(b.substr(6,2));
    
    h3 = h2-h1; m3 = m2-m1; s3 = s2-s1;
    if(s3<0){s3+=60; m3--;}
    if(m3<0){m3+=60; h3--;}
    if(h3<0) h3+=24;
    
    if(h3<10) cout << 0;
    cout << h3 << ":";
    if(m3<10) cout << 0;
    cout << m3 << ":";
    if(s3<10) cout << 0;
    cout << s3;
    return 0;
}