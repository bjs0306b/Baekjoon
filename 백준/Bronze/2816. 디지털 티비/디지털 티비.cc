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
    int pos1, pos2;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        if(s == "KBS1") pos1 = i;
        if(s == "KBS2") pos2 = i;
    }
    if(pos1 > pos2) pos2++;
    for(int i=0;i<pos1;i++) cout << 1;
    for(int i=0;i<pos1;i++) cout << 4;
    for(int i=0;i<pos2;i++) cout << 1;
    for(int i=0;i<pos2-1;i++) cout << 4;
    
    return 0;
}