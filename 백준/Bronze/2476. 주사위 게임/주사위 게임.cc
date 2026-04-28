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
    int mx = 0;
    while(n--){
        int a,b,c,num; cin>>a>>b>>c;
        if(a==b && b==c) num = 10000+a*1000;
        else if(a==b) num = 1000+100*a;
        else if(b==c) num = 1000+100*b;
        else if(a==c) num = 1000+100*c;
        else num = max({a,b,c})*100;

        if(mx < num) mx = num;
    }
    cout << mx;
    
    return 0;
}