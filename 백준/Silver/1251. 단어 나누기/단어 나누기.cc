#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    string mn = "{";
    for(int i=0;i<s.size()-2;i++){
        for(int j=i+1;j<s.size()-1;j++){
            string temp = s;
            reverse(temp.begin(), temp.begin()+i+1);
            reverse(temp.begin()+i+1, temp.begin()+j+1);
            reverse(temp.begin()+j+1, temp.end());

            if(mn > temp) mn = temp;      
        }
    }
    cout << mn;
    
    
    return 0;
}