#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,c; cin >> a >> b >> c;
    int sum1, sum2;
    sum1 = a*3+b*2+c;
    cin >> a >> b >> c;
    sum2 = a*3+b*2+c;
    if(sum1>sum2) cout << "A";
    else if(sum1<sum2) cout << "B";
    else cout << "T";
    return 0;
}