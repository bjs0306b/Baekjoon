#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str; cin >> str; vector<int> v;
    for(int i=str.size()-1;i>=0;i-=3){
        int m=1,sum = 0;
        for(int j=0;j<3 && i>=j;j++){
            int  n = str[i-j]-'0';
            sum += n*m;
            m *=2;
        }
        v.push_back(sum);
    }
    while(!v.empty()){
        cout << v.back();
        v.pop_back();
    }
    
    
    return 0;
}