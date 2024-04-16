#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        int sum = 0;
        for(int i=0;i<3;i++){
            sum += pow(26, 2-i) * (s[i] - 'A');
        }
        int num = stoi(s.substr(4));
        if(abs(sum-num) <= 100) cout << "nice\n";
        else cout << "not nice\n";
    }

    
    return 0;
}