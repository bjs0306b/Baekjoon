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
    int n;
    cin >> n;
    deque<int> dq;
    while (n--)
    {
        int num,a;
        cin >> num;
        switch (num)
        {
        case 1:
            cin >> a;
            dq.push_front(a);
            break;
        case 2:
            cin >> a;
            dq.push_back(a);
            break;
        case 3:
            if (dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            break;
        case 4:
            if (dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            break;
        case 5:
            cout << dq.size() << "\n";
            break;
        case 6:
            if (dq.empty())
                cout << "1\n";
            else
                cout << "0\n";
            break;
        case 7:
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.front() << "\n";
            break;
        case 8:
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.back() << "\n";
            break;
        }
    }

    return 0;
}