#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string n;
    cin >> n;
    long long sum = 0;
    int check=0;
    multiset<char, greater<>> ms;
    for(char a : n){
        if(a == '0') check=1;
        int num; num = a - '0';
        sum += num;
    }
    if(check && !(sum%3) && n != "0"){
        int cntt = 0;
        for(auto a : n){
            if(a != '0') ms.insert(a);
            else cntt++;
        }
        for(char b : ms) cout << b;
        for(int i=0;i<cntt;i++) cout << '0';
    }
    else cout << -1;
    
    return 0;
}