#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

class rankk
{
public:
    int name, gold, silver, bronze;
    rankk() {}
    rankk(int n, int g, int s, int b) : name(n), gold(g), silver(s), bronze(b) {}

    bool operator<(rankk other) const
    {
        if (gold == other.gold)
        {
            if (silver == other.silver)
            {
                if (bronze == other.bronze)
                {
                    return name < other.name; 
                }
                return bronze < other.bronze;
            }
            return silver < other.silver;
        }
        return gold < other.gold;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int bb, cc, dd;
    vector<rankk> v;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == n)
        {
            bb = b, cc = c, dd = d;
        }
        v.push_back(rankk(a, b, c, d));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i].bronze == dd && v[i].silver == cc && v[i].gold == bb) { cout << i+1; break;}
    }
    return 0;
}