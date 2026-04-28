#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, start, end;
    cin >> n;
    int arr[n];
    set<int> s;
    for(int i=0;i<n;i++){int num; cin >> num; arr[i] = num;}
    for(int i=1;i<n;i++){s.insert(arr[i]-arr[i-1]);}
    int dis;
    for(int temp = *s.begin();;temp--){
        bool check = true;
        for(auto a : s) if(a%temp!=0){check = false; break;}
        if(check){dis = temp; break;}
    }   
    cout << (arr[n-1] - arr[0])/dis-n+1;
    return 0;
}