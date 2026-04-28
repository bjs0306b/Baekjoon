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
int arr[400];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int y1,m1,d1,y2,m2,d2; cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    for(int i=0;i<=399;i+=4) arr[i] = 1;
    for(int i=100;i<=399;i+=100) arr[i] = 0;
    
    if(y2-y1 > 1000 || (y2-y1==1000 && m2 >= m1 && d2 >= d1)){cout << "gg"; return 0;}

    int sum = 0;
    if(y1 == y2){
        if(arr[y1%400] == 1){
            sum -= 366;
        }
        else sum -= 365;
    }
    for(int i = y1 + 1; i < y2; i++){
        if(arr[i%400] == 1) sum += 366;
        else sum += 365;
    }

    for(int i = m1; i <= 12; i++){
        if(i == 2){
            if(arr[y1%400] == 1) sum+=29;
            else sum+=28;
        }
        else if(i == 4 || i == 6 || i == 9 || i == 11) sum += 30;
        else sum += 31;
    }
    sum -= d1;

    for(int i = 1; i < m2; i++){
        if(i == 2){
            if(arr[y1%400] == 1) sum+=29;
            else sum+=28;
        }
        else if(i == 4 || i == 6 || i == 9 || i == 11) sum += 30;
        else sum += 31;
    }
    sum += d2;

    cout << "D-" << sum;

    
    return 0;
}