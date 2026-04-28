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
    while(n--){
        int a; cin >> a;
        bool check = false;
        for(int i=2;i<=64;i++){
            int temp = a;
            vector<int> v;
            while(temp){
                v.push_back(temp%i);
                temp/=i;
            } 
            int size = v.size()/2;
            bool check2 = true;
            for(int j=0;j<size;j++){
                if(v[j] != v[v.size()-1-j]){
                    check2 = false;
                    break;
                }
            }
            if(check2){check = true; break;}
        }
        if(check) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
    return 0;
}