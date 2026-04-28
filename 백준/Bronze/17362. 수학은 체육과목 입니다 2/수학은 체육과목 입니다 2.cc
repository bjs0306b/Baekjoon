#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    n = n%8;

    switch (n)
    {
    case 0:
    case 2:
        cout << 2;
        break;
    case 1:
        cout << 1;
        break;
    case 3:
    case 7:
        cout << 3;
        break;
    case 4:
    case 6:
        cout << 4;
        break;
    case 5:
        cout << 5;
        break;
    
    default:
        break;
    }
    
    return 0;
}   