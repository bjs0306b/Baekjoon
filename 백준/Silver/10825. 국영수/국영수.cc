#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class person
{
public:
    string name;
    int korea, english, math;
    person() {}
    person(string n, int k, int e, int m) : name(n), korea(k), english(e), math(m) {}

    bool operator<(person p)
    {
        if (korea == p.korea)
        {
            if (english == p.english)
            {
                if (math == p.math)
                {
                    return name < p.name;
                }
                return math > p.math;
            }
            return english < p.english;
        }
        return korea > p.korea;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    person p[n];
    for (int i = 0; i < n; i++)
    {
        string name;
        int k, e, m;
        cin >> name >> k >> e >> m;
        p[i] = person(name, k, e, m);
    }
    sort(p, p+n);
    for(int i=0;i<n;i++) cout << p[i].name << "\n";

    return 0;
}