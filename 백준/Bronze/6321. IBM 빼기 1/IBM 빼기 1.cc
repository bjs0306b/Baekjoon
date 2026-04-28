#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    string str;
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "String #" << i+1 << "\n";
        cin >> str;
        for(string::iterator iter = str.begin(); iter != str.end(); iter++){
            if(*iter == 'Z') cout << 'A';
            else{
                char c;
                c = *iter+1;
                cout << c;
            }
        }
        cout << "\n\n";
    }
    
    return 0;
}