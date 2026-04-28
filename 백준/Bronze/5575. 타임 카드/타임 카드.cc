#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i=0;i<3;i++){
        int h1,m1,s1,h2,m2,s2,h3,m3,s3;
        cin>>h1>>m1>>s1>>h2>>m2>>s2;
        if(s1>s2) {m2--; s3 = s2+60-s1;}
        else s3 = s2-s1;

        if(m1>m2) {h2--; m3 = m2+60-m1;}
        else m3 = m2-m1;

        h3 = h2-h1;

        cout << h3 <<" "<<m3<<" "<<s3<<"\n";
    }
    
    
    return 0;
}