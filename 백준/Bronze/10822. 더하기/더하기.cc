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
    int sum = 0;
    string temp = "";
    for(auto k : s){
        if(k == ','){
            sum += stoi(temp);
            temp = "";
        }
        else temp.push_back(k);
    }
    sum += stoi(temp);
    cout << sum;
    
    return 0;
}