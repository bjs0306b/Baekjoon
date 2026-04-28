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
    string s; 
    while(getline(cin , s)){
        auto iter = find(s.begin(),s.end(),' ');
        string s1 = s.substr(0,iter-s.begin());
        string s2 = s.substr(iter-s.begin()+1);
        // cout << s1 << " " <<  s2;
        auto iter1 = s1.begin();
        auto iter2 = s2.begin();
        int size1 = s1.size();
        int cnt = 0;
        bool flag = false;
        while(iter2 != s2.end()){
            if(*iter1 == *iter2){
                iter1++; iter2++;
                cnt++;
                if(cnt == size1){flag = true; break;}
            }
            else{
                iter2++;
            }
        }
        if(flag) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
    
    
    return 0;
}