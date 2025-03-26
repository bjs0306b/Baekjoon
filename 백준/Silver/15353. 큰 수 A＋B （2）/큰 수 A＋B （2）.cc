#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;

    int size1 = s1.size(), size2 = s2.size();
    if (size1 > size2)
    {
        for (int i = 0; i <= size1 - size2; i++)
            s2 = '0' + s2;
    }
    else
    {
        for (int i = 0; i <= size2 - size1; i++)
            s1 = '0' + s1;
    }

    deque<int> deq;
    auto riter1 = s1.rbegin(), riter2 = s2.rbegin();
    bool flag = false;
    for (; riter1 != s1.rend() && riter2 != s2.rend(); riter1++, riter2++)
    {
        int num1 = *riter1 - '0', num2 = *riter2 - '0';
        int temp = num1 + num2;
        if (flag)
        {
            flag = false;
            temp++;
        }
        if (temp > 9)
        {
            flag = true;
            temp -= 10;
            deq.push_front(temp);
        }
        else
            deq.push_front(temp);
    }
    if (flag)
        deq.push_front(1);

    for (auto k : deq)
        cout << k;

    return 0;
}