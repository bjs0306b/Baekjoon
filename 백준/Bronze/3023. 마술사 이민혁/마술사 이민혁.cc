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
    int a,b; cin >> a >> b;
    char arr[a][b]; for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin >> arr[i][j];
    int x,y; cin >> x >> y;
    x--; y--;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(i==x && j==y){
                if(arr[i][j] == '.') cout << '#';
                else cout << '.'; 
            }
            else cout << arr[i][j];
        }

        for(int j=b;j<2*b;j++){
            if(i==x && j==y){
                if(arr[i][2*b-1-j] == '.') cout << '#';
                else cout << '.'; 
            }
            else cout << arr[i][2*b-1-j];
        }
        cout << '\n';
    }
    for(int i=a;i<2*a;i++){
        for(int j=0;j<b;j++){
            if(i==x && j==y){
                if(arr[2*a-1-i][j] == '.') cout << '#';
                else cout << '.'; 
            }
            else cout << arr[2*a-1-i][j];
        }
        for(int j=b;j<2*b;j++){
            if(i==x && j==y){
                if(arr[2*a-1-i][2*b-1-j] == '.') cout << '#';
                else cout << '.'; 
            }
            else cout << arr[2*a-1-i][2*b-1-j];
        }
        cout << '\n';
    }
    
    
    return 0;
}