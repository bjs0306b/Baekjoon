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
    int a,b,cnt=0; cin >> a >> b;
    char arr[a][b]; for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin >> arr[i][j];

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(arr[i][j] != '.'){
                if(arr[i][j] == '-'){
                    int temp = j;
                    while(arr[i][temp] == '-'){
                        arr[i][temp] = '.';
                        temp++;
                        if(temp == b) break;
                    }
                    cnt++;
                }
                else{
                    int temp = i;
                     while(arr[temp][j] == '|'){
                        arr[temp][j] = '.';
                        temp++;
                        if(temp == a) break;
                    }
                    cnt++;
                }
            }   
        }     
    }
    cout << cnt;
    
    return 0;
}