#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str; cin >>str;
    vector<int> vec;
    for(int i=0;i<str.size();i++){
        int num; num = str[i] - '0';
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++){
        cout << *iter;
    }
    
    
    return 0;
}