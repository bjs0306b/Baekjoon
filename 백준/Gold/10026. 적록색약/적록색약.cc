#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
char arr1[100][100],arr2[100][100];
int n; 
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};
void func1(int i, int j, char col){
    for(int k=0;k<4;k++){
        int nx = i + x[k];
        int ny = j + y[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(arr1[nx][ny] == col){
            arr1[nx][ny] = '.';
            func1(nx,ny,col);
        }
    }
}
void func2(int i, int j, char col){
    for(int k=0;k<4;k++){
        int nx = i + x[k];
        int ny = j + y[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(arr2[nx][ny] == col){
            arr2[nx][ny] = '.';
            func2(nx,ny,col);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr1[i][j];
            arr2[i][j] = arr1[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr1[i][j] == 'R') arr1[i][j] = 'G';
        }
    }

    int cnt1 = 0, cnt2 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr1[i][j] != '.'){
                cnt1++;
                func1(i,j, arr1[i][j]);
            }
            if(arr2[i][j] != '.'){
                cnt2++;
                func2(i,j, arr2[i][j]);
            }
        }
    }
    cout << cnt2 << " " << cnt1;
    return 0;
}

