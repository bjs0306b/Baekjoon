#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int sum = 0;
    switch (a)
    {
    case 1:
        sum += b;
        break;
    case 2:
        sum += 31 + b;
        break;
    case 3:
        sum += 59 + b;
        break;
    case 4:
        sum += 90 + b;
        break;
    case 5:
        sum += 120 + b;
        break;
    case 6:
        sum += 151 + b;
        break;
    case 7:
        sum += 181 + b;
        break;
    case 8:
        sum += 212 + b;
        break;
    case 9:
        sum += 243 + b;
        break;
    case 10:
        sum += 273 + b;
        break;
    case 11:
        sum += 304 + b;
        break;
    case 12:
        sum += 334 + b;
        break;
    }
    sum--;
    string dow[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cout << dow[sum%7];
    return 0;
}