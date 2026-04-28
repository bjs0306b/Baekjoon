#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str[5];
    for (int i = 0; i < 5; i++)
        cin >> str[i];
  
    string::iterator it1 = str[0].begin(), it2 = str[1].begin(), it3 = str[2].begin(), it4 = str[3].begin(), it5 = str[4].begin();
    while (!(it1 == str[0].end() && it2 == str[1].end() &&it3 == str[2].end() &&it4 == str[3].end() &&it5 == str[4].end()))
    {
        if(it1 != str[0].end()){
            cout << *it1;
            it1++;
        }
        if(it2 != str[1].end()){
            cout << *it2;
            it2++;
        }
        if(it3 != str[2].end()){
            cout << *it3;
            it3++;
        }
        if(it4 != str[3].end()){
            cout << *it4;
            it4++;
        }
        if(it5 != str[4].end()){
            cout << *it5;
            it5++;
        }
    }
    return 0;
}