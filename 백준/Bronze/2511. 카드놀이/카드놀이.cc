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
    int arr[2][10];
    for(int i=0;i<2;i++)
        for(int j=0;j<10;j++) cin >> arr[i][j];
    
    char lastest_win = 'D';
    int a_point=0, b_point=0;
    for(int i=0;i<10;i++){
        if(arr[0][i] > arr[1][i]){
            a_point += 3;
            lastest_win = 'A';
        }
        else if(arr[0][i] < arr[1][i]){
            b_point += 3;
            lastest_win = 'B';
        }
        else{
            a_point++; b_point++;
        }
    }
    cout << a_point << " " << b_point << "\n";
    if(a_point > b_point){
        cout << "A";
    }
    else if(a_point < b_point) cout << "B";
    else{
        if(lastest_win == 'D') cout << "D";
        else cout << lastest_win;
    }
    return 0;
}