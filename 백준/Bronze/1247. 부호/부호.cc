#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 3; i++)
    {
        int num;
        cin >> num;
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for (int j = 0; j < num; j++)
        {
            string s;
            cin >> s;
            if (s[0] == '-')
            {
                int temp = 0;
                for (auto iter = s.rbegin(); iter != s.rend() - 1; iter++)
                {
                    arr[temp++] -= *iter - '0';
                }
            }
            else
            {
                int temp = 0;
                for (auto iter = s.rbegin(); iter != s.rend(); iter++)
                {
                    arr[temp++] += *iter - '0';
                }
            }

            for (int k = 0; k < 25; k++)
            {
                arr[k + 1] += arr[k] / 10;
                arr[k] %= 10;
            }
        }
        bool check = true;
        for (int j = 25; j >= 0; j--)
        {
            if (arr[j] != 0)
            {
                if (arr[j] < 0)
                {
                    cout << "-\n";
                    check = false;
                    break;
                }
                else
                {
                    cout << "+\n";
                    check = false;
                    break;
                }
            }
        }
        if(check) cout << "0\n";
    }

    return 0;
}