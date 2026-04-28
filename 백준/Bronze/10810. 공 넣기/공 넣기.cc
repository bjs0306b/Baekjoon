#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int arr[a + 1];
    for (int i = 1; i < a + 1; i++)
        arr[i] = 0;
    for (int i = 0; i < b; i++)
    {
        int c, d, e;
        cin >> c >> d >> e;
        for (int j = c; j < d + 1; j++)
            arr[j] = e;
    }
    for (int i = 1; i < a + 1; i++)
        cout << arr[i] << " ";

    return 0;
}