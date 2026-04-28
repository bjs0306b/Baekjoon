#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<int> vec;
    vector<int>::iterator iter;
    int sum=0;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        if(num == 0) vec.pop_back();
        else vec.push_back(num);
    }
    for(iter = vec.begin(); iter!=vec.end();iter++) sum += *iter;

    cout << sum;
    return 0;
}