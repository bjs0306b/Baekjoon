#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b; cin>>a>>b;
    vector<string> v;
    string arr[a]; for(int i=0;i<a;i++) cin >> arr[i];
    for(int i=0;i<b;i++){
        string str; cin >> str;
        v.push_back(str);
    }
    int cnt = 0;
    sort(v.begin(), v.end());
    for(int i=0;i<a;i++){
        if(binary_search(v.begin(), v.end(), arr[i])) cnt+=count(v.begin(), v.end(), arr[i]);
    }
    cout << cnt;
    
    return 0;
}