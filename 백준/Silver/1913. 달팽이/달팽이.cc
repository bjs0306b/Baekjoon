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
    int k; cin >> k;
    int arr[n][n];
    int cnt = 1;
    int x = n/2, y = n/2;
    int plus=1;
    arr[x][y] = cnt++;
    bool escape = false;
    for(;;){

        for(int i=0;i<plus;i++){
            if(x == 0){escape = true; break;}
            arr[--x][y] = cnt++;
        }
        if(escape) break;
        for(int i=0;i<plus;i++){
            arr[x][++y] = cnt++;
        }
        plus++;
        for(int i=0;i<plus;i++){
            arr[++x][y] = cnt++;
        }
        for(int i=0;i<plus;i++){
            arr[x][--y] = cnt++;
        }
        plus++;
    }
    int ansx, ansy;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << ' ';
            if(arr[i][j] == k){
                ansx = i;
                ansy = j;}
        }
        cout << '\n';
    }
    cout << ansx+1 << ' ' << ansy+1;
    return 0;
}