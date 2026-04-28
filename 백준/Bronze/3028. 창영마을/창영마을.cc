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
    string s; cin >> s;
    int arr[3] = {1,0,0};
    for(auto k : s){
        if(k == 'A') swap(arr[0],arr[1]);
        else if(k == 'B') swap(arr[1],arr[2]);
        else swap(arr[0],arr[2]);
    }
    for(int i=0;i<3;i++) if(arr[i]) cout << i+1 << "\n";
    
    
    return 0;
}