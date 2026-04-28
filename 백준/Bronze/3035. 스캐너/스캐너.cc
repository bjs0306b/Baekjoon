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
    int a,b,c,d; cin >> a >> b >> c >> d; char arr[a][b];
    for(int i=0;i<a;i++){
        string s; cin >> s;
        for(int j=0;j<b;j++){
            arr[i][j] = s[j];
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<c;j++){
            for(int k=0;k<b;k++){
                for(int l=0;l<d;l++){
                    cout << arr[i][k];
                }
            }
            cout << "\n";
        }
    }
    
    return 0;
}