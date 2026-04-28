#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string str;
    long long n;
    cin >> str >> n;
    long long mul = 1;
    long long sum = 0;
    for(string::reverse_iterator riter = str.rbegin(); riter != str.rend(); riter++){
        long long s;
        if(*riter >= 'A' && *riter <= 'Z') s = *riter - 'A' + 10;
        else s = *riter - '0';
        sum += s*mul;
        mul *= n;
    }
    cout << sum;
    
    
    return 0;
}