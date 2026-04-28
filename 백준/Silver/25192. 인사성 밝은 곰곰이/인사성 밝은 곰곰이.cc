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
    int n; cin >> n;
    int sum = 0;
    set<string> se;
    while(n--){
        string s; cin >> s;
        if(s == "ENTER"){
            sum += se.size();
            se.clear();
        }
        else{
            se.insert(s);
        }
    }
    sum += se.size();
    cout << sum;
    return 0;
}