#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string str;
    deque<int> d;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "push")
        {
            int num;
            cin >> num;
            d.push_back(num);
        }
        else if (str == "front")
        {
            if (d.size())
                cout << d.front() << "\n";
            else
                cout << -1 << "\n";
        }
        else if (str == "pop")
        {
            if (d.size())
            {
                cout << d.front() << "\n";
                d.pop_front();
            }
            else
                cout << -1 << "\n";
        }
        else if (str == "size")
            cout << d.size() << "\n";
        else if (str == "empty")
            cout << d.empty() << "\n";
        else if (str == "back")
        {
            if (d.size())
                cout << d.back() << "\n";
            else
                cout << -1 << "\n";
        }
    }

    return 0;
}