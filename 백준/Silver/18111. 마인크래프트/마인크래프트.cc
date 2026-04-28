#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, b;
    cin >> n >> m >> b;
    int k = m * n;
    vector<int> vec;
    vector<int>::iterator iter;
    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        b += num;
        vec.push_back(num);
    }
    int aver = b / k;
    int min = 2147483647;
    int floor;
    for (int i = aver; i >= 0; i--)
    {
        int sum = 0;
        for (iter = vec.begin(); iter != vec.end(); iter++)
        {
            int sub = i - *iter;
            if (sub < 0)
                sum -= 2 * sub;
            else
                sum += sub;
        }
        if (min > sum)
        {
            min = sum;
            floor = i;
        }
    }
    cout << min << " " << floor;

    return 0;
}