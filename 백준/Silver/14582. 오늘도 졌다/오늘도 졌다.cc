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
    int arr[2][9];
    for(int i=0;i<2;i++){
        for(int j=0;j<9;j++){
            cin >> arr[i][j];
        }
    }
    int scorea=0,scoreb=0;
    bool win = false;
    for(int i=0;i<9;i++){
        scorea += arr[0][i];
        if(scorea > scoreb)
            win = true;
        scoreb += arr[1][i]; 
    }
    if(win && scorea < scoreb) cout << "Yes";
    else cout << "No"; 
    
    
    return 0;
}