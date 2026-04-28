#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str;
    vector<int> vec;
    for(int i=1;i<6;i++){
        cin >> str;
        int index = str.find("FBI");
        if(index != string::npos)
            vec.push_back(i);
    }
    if(vec.empty()) cout << "HE GOT AWAY!";
    else{
        for(vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) cout << *iter << " ";
    }
    
    return 0;
}