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
        arr[i] = i;
    for (int i = 0; i < b; i++)
    {
        int m, n;
        cin >> m >> n;
        swap(arr[m], arr[n]);
    }
    for (int i = 1; i < a + 1; i++)
        cout << arr[i] << " ";

    return 0;
}