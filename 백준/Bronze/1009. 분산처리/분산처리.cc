#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        long long a, b;
        cin >> a >> b;
        a = a % 10;
        long long num = a;
        for (long long j = 1; j < b; j++)
        {
            num *= a;
            num %= 10;
        }
        if(num == 0) num = 10;
        cout << num << "\n";
    }

    return 0;
}