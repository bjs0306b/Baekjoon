#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sum = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'S')
            sum++;
        else if (s[i] == 'L')
        {
            sum++;
            i++;
        }
    }
    cout << min(sum, n);
    return 0;
}