#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;

class student
{
public:
    string name;
    int day, month, year;

    student() {}
    student(string n, int d, int m, int y) : name(n), day(d), month(m), year(y) {}

    bool operator<(student other)
    {
        if (year == other.year)
        {
            if (month == other.month)
            {
                if (day == other.day)
                    return name < other.name;
                return day < other.day;
            }
            return month < other.month;
        }
        return year < other.year;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<student> v;
    for (int i = 0; i < n; i++)
    {
        string name;
        int day, month, year;
        cin >>name >> day>>month>>year;
        v.push_back(student(name, day, month, year));
    }
    sort(v.begin(), v.end());
    cout << v[v.size()-1].name << "\n" << v[0].name;

    return 0;
}