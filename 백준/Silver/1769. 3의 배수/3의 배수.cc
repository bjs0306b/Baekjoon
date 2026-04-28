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
    string s; cin >> s;
    int cnt = 0;
    while(s.size() != 1){
        int sum = 0; cnt++;
        for(int i=0;i<s.size();i++){
            int num = s[i] - '0';
            sum += num;
        }
        s = to_string(sum);
    }
    cout << cnt << "\n";
    if(stoi(s)%3) cout << "NO";
    else cout << "YES";
    
    
    return 0;
}