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
    vector<pair<int, string>> v;
    v.push_back({1967, "DavidBowie"});
    v.push_back({1969, "SpaceOddity"});
    v.push_back({1970, "TheManWhoSoldTheWorld"});
    v.push_back({1971, "HunkyDory"});
    v.push_back({1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"});
    v.push_back({1973, "AladdinSane"});
    v.push_back({1973, "PinUps"});
    v.push_back({1974, "DiamondDogs"});
    v.push_back({1975, "YoungAmericans"});
    v.push_back({1976, "StationToStation"});
    v.push_back({1977, "Low"});
    v.push_back({1977, "Heroes"});
    v.push_back({1979, "Lodger"});
    v.push_back({1980, "ScaryMonstersAndSuperCreeps"});
    v.push_back({1983, "LetsDance"});
    v.push_back({1984, "Tonight"});
    v.push_back({1987, "NeverLetMeDown"});
    v.push_back({1993, "BlackTieWhiteNoise"});
    v.push_back({1995, "1.Outside"});
    v.push_back({1997, "Earthling"});
    v.push_back({1999, "Hours"});
    v.push_back({2002, "Heathen"});
    v.push_back({2003, "Reality"});
    v.push_back({2013, "TheNextDay"});
    v.push_back({2016, "BlackStar"});

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int a, b;
        cin >> a >> b;
        vector<pair<int, string>> p;
        for (auto k : v)
        {
            if (k.first < a)
                continue;
            if (k.first > b)
                break;
            cnt++;
            p.push_back({k.first, k.second});
        }
        cout << cnt << "\n";
        for (auto k : p)
            cout << k.first << " " << k.second << "\n";
    }

    return 0;
}