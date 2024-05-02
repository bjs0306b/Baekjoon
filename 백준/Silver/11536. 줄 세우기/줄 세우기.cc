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
string pre="";
int state; // 1:ascending, 2:descending, 0:unknown
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    for(int i=0;i<n;i++){
        string s; cin >> s;
    
        if(pre != ""){
            if(state){
                if(pre < s && state != 1){
                    cout << "NEITHER";
                    return 0;
                }
                else if(pre > s && state != 2){
                    cout << "NEITHER";
                    return 0;
                }
            }
            else{
                if(pre < s){
                    state = 1;
                }
                else if(pre > s){
                    state = 2;
                }
            }
            pre = s;
        }   
        else pre = s;
    }
    if(state == 1){
        cout << "INCREASING";
    }
    else if(state == 2){
        cout << "DECREASING";
    }
    else{
        cout << "NEITHER";
    }
    
    return 0;
}