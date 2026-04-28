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
int arr[100][100];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin >> a >> b;
    for(int i=0;i<a;i++){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        for(int j=x1;j<=x2;j++){
            for(int k=y1;k<=y2;k++){
                arr[j][k]++;
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(arr[i][j] > b) cnt++;
        }
    }
    cout << cnt;
    
    return 0;
}