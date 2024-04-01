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
    string s; cin >> s;
    long long sum = 0;
    for(int i=0;i<5;i++){
        int temp = s[i] - '0';
        sum += pow(temp,5);
    }
    cout << sum;
    
    
    return 0;
}