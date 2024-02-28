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
    int n; cin >> n; int cnt = 0;
    for(int i=0;i<5;i++){
        int num; cin >> num; if(n == num) cnt++;
    }
    cout << cnt;
    return 0;
}