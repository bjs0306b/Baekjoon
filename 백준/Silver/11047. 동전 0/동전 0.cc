#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    int arr[a];
    for (int i = 0; i < a; i++)
        cin >> arr[i];
    for (int i = a - 1; i >= 0 && b > 0; i--)
    {
        while (b >= arr[i])
        {
            b -= arr[i];
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}