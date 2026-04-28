#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int note1; cin >> note1;
        set<int> s; for(int i=0;i<note1;i++){int num; cin >> num; s.insert(num);}
        int note2; cin >> note2;
        for(int i=0;i<note2;i++){
            int num; cin >> num;
            if(s.find(num) != s.end()) cout << "1\n";
            else cout << "0\n";
        }
        
    }
    
    return 0;
}