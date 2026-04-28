#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(1){
        getline(cin,s);
        if(s == "#") break;
        cout << count(s.begin(), s.end(), 'a') + count(s.begin(), s.end(), 'e') + count(s.begin(), s.end(), 'i') + count(s.begin(), s.end(), 'o') + count(s.begin(), s.end(), 'u')
        + count(s.begin(), s.end(), 'A') + count(s.begin(), s.end(), 'E') + count(s.begin(), s.end(), 'I') + count(s.begin(), s.end(), 'O') + count(s.begin(), s.end(), 'U') <<"\n";
    }

    return 0;
}