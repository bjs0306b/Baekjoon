#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, sum=0;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    long long a, b;
    cin >> a >> b;
    for (long long i = 0; i < n; i++)
    {
        if (arr[i] - a + b - 1 >= 0)
            sum += ((arr[i] - a + b - 1) / b);
    }
    cout << sum + n;
    return 0;
}