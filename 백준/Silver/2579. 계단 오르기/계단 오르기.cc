#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[n], arr2[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr2[0] = arr[0];
    arr2[1] = arr[0] + arr[1];
    arr2[2] = max(arr[0] + arr[2], arr[1]+arr[2]);
    for (int i = 3; i < n; i++)
    {
        arr2[i] = max(arr2[i - 2] + arr[i], arr2[i - 3] + arr[i - 1] + arr[i]);
    }
    cout << arr2[n - 1];
    return 0;
}