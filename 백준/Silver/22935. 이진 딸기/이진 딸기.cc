#include <bits/stdc++.h>
using namespace std;

string to_binary(int num)
{
    string ret = "";
    while (num)
    {
        char temp = num % 2 + '0';
        ret += temp;
        num /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        --num %= 28;

        if (num > 14)
            num = 28 - num;
        string binary = to_binary(++num);

        if (binary.size() < 4)
        {
            for (int i = binary.size(); i < 4; i++)
                cout << 'V';
        }
        for (auto k : binary)
        {
            if (k == '0')
                cout << 'V';
            else
                cout << "딸기";
        }

        cout << "\n";
    }

    return 0;
}