#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str;
    cin >> str;
    int sixteen=1;
    int sum = 0;
    for(string::reverse_iterator iter = str.rbegin(); iter != str.rend(); iter++){
        int s;
        if(*iter >= 'A' && *iter <= 'F')
            s = *iter - 'A' + 10;
        else if(*iter >= '0' && *iter <= '9')
            s = *iter - '0';
        sum += sixteen * s;
        sixteen *= 16;
    }
    cout << sum;

    
    return 0;
}