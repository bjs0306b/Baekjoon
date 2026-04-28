#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    int i=0;
    while(str[i] != '\0'){
        cout << str[i]; i++;
        if(i%10==0) cout <<"\n";
    }

    return 0;
}