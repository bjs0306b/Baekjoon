#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int arr[9][9];
    int max = -1;
    int ii, jj;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int num;
            cin >> num;
            if (num > max)
            {
                max = num;
                ii = i + 1;
                jj = j + 1;
            }
        }
    }
    cout << max << "\n"
         << ii << " " << jj;

    return 0;
}