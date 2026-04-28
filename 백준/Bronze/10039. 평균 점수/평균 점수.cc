#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;
        if(num < 40) num = 40;  
        sum += num;
    }
    cout << sum/5;

    return 0;
}