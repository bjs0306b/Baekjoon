#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> v = {INT32_MAX};
    vector<int> pos;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        arr.push_back(num);
        
        if(v.back() < num){
            v.push_back(num);
            pos.push_back(v.size()-1);
        }
        else{
            auto iter = lower_bound(v.begin(), v.end(), num);
            *iter = num;
            pos.push_back(iter-v.begin());
        }
    }
    cout << v.size() << "\n";
    
    vector<int> index;
    int temp = v.size()-1;
    for(int i = n-1; i>=0; i--){
        if(pos[i] == temp){
            index.push_back(i);
            temp--;
        }
    }
    
    for(auto riter = index.rbegin(); riter != index.rend(); riter++) cout << arr[*riter] << " ";

    return 0;
}