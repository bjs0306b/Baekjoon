#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long sum = 0;
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        char a;
        cin >> a;
        if (a >= '0' && a <= '9')
            temp += a;
        else
        {
            if (temp.size() > 0)
            {
                int num = stoi(temp);
                temp = "";
                sum += num;
            }
        }
    }
    if (temp.size() > 0)
    {
        int num = stoi(temp);
        sum += num;
    }
    cout << sum;

    return 0;
}