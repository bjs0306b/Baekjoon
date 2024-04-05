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
    string s; cin >> s; auto iter = s.begin();
    char arr[s.size()/n][n];
    for(int i=0;i<s.size()/n;i++){
        for(int j=0;j<n;j++){
            if(i%2==0){
                arr[i][j] = *iter++;
            }
            else{
                arr[i][n-j-1] = *iter++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<s.size()/n;j++){
            cout << arr[j][i];
        }
    }
    
    
    return 0;
}