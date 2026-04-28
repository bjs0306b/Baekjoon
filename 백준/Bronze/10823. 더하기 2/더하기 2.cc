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
    string s;
    int sum = 0;
    string temp = "";
    while (getline(cin, s))
    {
        for (auto k : s)
        {
            if (k == ',')
            {
                int num = stoi(temp);
                sum += num;
                temp = "";
            }
            else
            {
                temp.push_back(k);
            }
        }
    }
    int num = stoi(temp);
    sum += num;
    cout << sum;
    return 0;
}