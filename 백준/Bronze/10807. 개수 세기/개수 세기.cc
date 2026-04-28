#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    vector<int> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        vec.push_back(num);
    }
    int num; cin >> num;
    cout << count(vec.begin(), vec.end(), num);
    
    return 0;
}