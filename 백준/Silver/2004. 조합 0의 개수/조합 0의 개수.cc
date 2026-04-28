#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int cnt_five, cnt_two;
void func(int m, bool plus){
    int n = m;
    int cnt = 0;
    int fi = 0;
    for(;;){
        cnt += n % 5 * fi;
        n /= 5;
        fi = fi*5 + 1;
        if(n==0) break;
    }
    n = m;
    int cnt2 = 0;
    int tw = 0;
    for(;;){
        cnt2 += n % 2 * tw;
        n /= 2;
        tw = tw*2 + 1;
        if(n==0) break;
    }
    if(plus){cnt_five += cnt; cnt_two += cnt2;}
    else{cnt_five -= cnt; cnt_two -= cnt2;}
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    func(a,1); func(b,0); func(a-b,0);
    cout << min(cnt_five, cnt_two);
    
    return 0;
}