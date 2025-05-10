#include <bits/stdc++.h>
using namespace std;
int score[2];
pair<int, int> tim[2];
pair<int, int> ans[2];
bool before[2]; // 이전 결과. f,f = 비김 t,f = A가 이김, f,t = B가 이김
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    while (n--)
    {
        int a;
        cin >> a;
        score[a - 1]++;
        string s;
        cin >> s;
        int min = stoi(s.substr(0, 2));
        int sec = stoi(s.substr(3, 2));

        if (score[0] > score[1])
        {
            if (before[0])
            {
                continue;
            }
            else if (before[1])
            {
                continue;
            }
            else
            {
                tim[0] = {min, sec};
            }
            before[0] = true, before[1] = false;
        }
        else if (score[0] < score[1])
        {
            if (before[0])
            {
                continue;
            }
            else if (before[1])
            {
                continue;
            }
            else
            {
                tim[1] = {min, sec};
            }
            before[1] = true, before[0] = false;
        }
        else
        {
            if (before[0])
            {
                int add_min = min - tim[0].first;
                int add_sec = sec - tim[0].second;
                if (add_sec < 0)
                {
                    add_sec += 60;
                    add_min--;
                }
                ans[0].first += add_min;
                ans[0].second += add_sec;
            }
            else if (before[1])
            {
                int add_min = min - tim[1].first;
                int add_sec = sec - tim[1].second;
                if (add_sec < 0)
                {
                    add_sec += 60;
                    add_min--;
                }
                ans[1].first += add_min;
                ans[1].second += add_sec;
            }
            else
            {
                continue;
            }
            before[0] = false, before[1] = false;
        }
    }
    if (before[1])
    {
        int add_min = 48 - tim[1].first;
        int add_sec = 0 - tim[1].second;
        if (add_sec < 0)
        {
            add_sec += 60;
            add_min--;
        }
        ans[1].first += add_min;
        ans[1].second += add_sec;
    }
    else if(before[0])
    {
        int add_min = 48 - tim[0].first;
        int add_sec = 0 - tim[0].second;
        if (add_sec < 0)
        {
            add_sec += 60;
            add_min--;
        }
        ans[0].first += add_min;
        ans[0].second += add_sec;
    }

    ans[0].first += (ans[0].second / 60);
    ans[0].second %= 60;
    ans[1].first += (ans[1].second / 60);
    ans[1].second %= 60;

    if (ans[0].first < 10)
        cout << "0" << ans[0].first << ":";
    else
        cout << ans[0].first << ":";

    if (ans[0].second < 10)
        cout << "0" << ans[0].second << "\n";
    else
        cout << ans[0].second << "\n";

    if (ans[1].first < 10)
        cout << "0" << ans[1].first << ":";

    else
        cout << ans[1].first << ":";

    if (ans[1].second < 10)
        cout << "0" << ans[1].second;

    else
        cout << ans[1].second;

    return 0;
}