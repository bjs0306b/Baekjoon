#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int arr[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
    deque<int> dq;
    for (int i = 0; i < a.size(); i++)
    {
        dq.push_back(arr[a[i] - 'A']);
        dq.push_back(arr[b[i] - 'A']);
    }
    for (int i = a.size() * 2 - 1; i >= 2; i--)
    {
        for (int j = 0; j < i; j++)
        {
            dq.push_back((dq[j] + dq[j + 1]) % 10);
        }
        for (int j = 0; j <= i; j++)
        {
            dq.pop_front();
        }
    }
    cout << dq[0] << dq[1];

    return 0;
}