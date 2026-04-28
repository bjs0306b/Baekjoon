#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int num; cin >>num; v.push_back(num);
    }
    sort(v.begin(), v.end());
    int num=0;
    for(auto s : v) num += (n--)*s;
    cout << num;
    return 0;
}