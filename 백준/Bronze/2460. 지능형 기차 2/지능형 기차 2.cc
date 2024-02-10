#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[11];
    arr[0] = 0;
    for (int i = 1; i < 11; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[i] = arr[i - 1] - a + b;
    }
    cout << *max_element(arr, arr+11);

    return 0;
}