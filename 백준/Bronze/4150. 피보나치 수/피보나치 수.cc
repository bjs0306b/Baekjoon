#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

string add(string a, string b){
    int max_size = max(a.size(), b.size());
    int arr[max_size+1]; memset(arr, 0, sizeof(arr));
    if(a.size() < b.size()) swap(a, b);
    auto iter_a = a.end()-1, iter_b = b.end()-1;
    for(int i=0;i<b.size();i++){
        arr[i] = (*iter_a - '0') + (*iter_b - '0');
        iter_a--; iter_b--;
    }
    for(int i=b.size();i<a.size();i++){
        arr[i] = *iter_a - '0';
        iter_a--;
    }
    for(int i=0;i<max_size;i++){
        if(arr[i] >= 10){
            arr[i] -= 10;
            arr[i+1]++;
        }
    }
    string ret = "";
    bool check = false;
    for(int i=max_size;i>=0;i--){
        if(arr[i] != 0) check = true;
        if(check) ret += to_string(arr[i]);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    string a,b,c;
    a = "1", b = "1", c= "2";
    if(n == 1 || n == 2) cout << 1;
    else if(n == 3) cout << 2;
    else{
        for(int i=0;i<n-3;i++){
            a = b;
            b = c;
            c = add(a, b);
        }
        cout << c;
    } 
    
    return 0;
}