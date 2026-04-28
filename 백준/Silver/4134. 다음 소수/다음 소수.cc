#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

bool sosu(long long n)
{

    for (long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    while (n--)
    {
        long long num;
        cin >> num;
        if (num < 3)
            cout << 2 << "\n";
        else
        {
            for (long long i = num;; i++)
            {
                if (sosu(i))
                {
                    cout << i << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}