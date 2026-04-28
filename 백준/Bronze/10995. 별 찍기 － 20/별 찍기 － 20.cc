#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
            for (int j = 0; j < n; j++)
                cout << " *";
        else
            for (int j = 0; j < n; j++)
                cout << "* ";
        cout << "\n";
    }

    return 0;
}