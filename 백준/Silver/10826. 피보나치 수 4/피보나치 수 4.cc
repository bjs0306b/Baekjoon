#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

string pluss(string a, string b){
    int lena = a.size(), lenb = b.size();
    int mn = min(lena,lenb), mx = max(lena, lenb);
    vector<int> v;
    for(int i=0;i<mn;i++){
        int numa = a[lena-1-i] - '0', numb = b[lenb-1-i] - '0';
        v.push_back(numa+numb);
    }
    if(lena > lenb){
        for(int i=mx-mn-1;i>=0;i--){
            int num = a[i] - '0';
            v.push_back(num);
        }
    }
    else if(lena < lenb){
        for(int i=mx-mn-1;i>=0;i--){
            int num = b[i] - '0';
            v.push_back(num);
        }
    }
    v.push_back(0);

    for(int i=0;i<v.size()-1;i++){
        if(v[i] >= 10){v[i]-=10; v[i+1]++;}
    }
    string temp;
    for(auto riter = v.rbegin(); riter != v.rend(); riter++){
        if(riter == v.rbegin() && *riter == 0) continue;
        char c = *riter + '0';
        temp.push_back(c);
    }
    return temp;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >>n;
    
    string a = "0", b = "1", c = "1";
    if(n==0) cout << 0;
    else if(n==1) cout << 1;
    else{
        for(int i=0;i<n-2;i++){
            a = b; b = c; c = pluss(a,b);
        }
        cout << c;
    }
    
    return 0;
}