#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int arr[26];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    while(getline(cin, s)){
        for(auto a : s){
            if(a != ' '){
                int num = a -'a';
                arr[num]++;
            }
        }
    }
    int mx = *max_element(arr, arr+26);
    for(int i=0;i<26;i++){
        if(arr[i] == mx){
            char c = 'a' + i;
            cout << c;
        }
    }
    
    
    return 0;
}