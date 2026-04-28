#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int cnt = 0;
    for(int i=0;i<8;i++){
        string str; cin >> str;
        for(int j=i%2;j<8;j+=2){
            if(str[j] == 'F')  cnt++;
        }
    }
    cout << cnt;
    
    
    return 0;
}