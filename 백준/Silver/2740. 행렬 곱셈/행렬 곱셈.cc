#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b;
    int arr[a][b];
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            cin >> arr[i][j];
    cin >> c >> d;
    int arr2[c][d];
    for (int i = 0; i < c; i++)
        for (int j = 0; j < d; j++)
            cin >> arr2[i][j];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < d; j++)
        {
            int sum = 0;
            for (int k = 0; k < c; k++)
                sum += arr[i][k] * arr2[k][j];
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}