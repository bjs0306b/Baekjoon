#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int arr[4];
    memset(arr, 0, 16);
    for (auto a : s)
    {
        if (a == 'L')
            arr[0]++;
        else if (a == 'O')
            arr[1]++;
        else if (a == 'V')
            arr[2]++;
        else if (a == 'E')
            arr[3]++;
    }
    int num;
    cin >> num;
    int mx = 0; string mx_str;
    while (num--)
    {
        int arr2[4];
        for (int i = 0; i < 4; i++)
            arr2[i] = arr[i];
        string str;
        cin >> str;
        for (auto a : str)
        {
            if (a == 'L')
                arr2[0]++;
            else if (a == 'O')
                arr2[1]++;
            else if (a == 'V')
                arr2[2]++;
            else if (a == 'E')
                arr2[3]++;
        }
        int sum = 1;
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                sum *= (arr2[i]+arr2[j]);
            }
        }
        sum %= 100;
        if(mx_str.size()==0) {mx_str = str; mx = sum;}
        else if(sum == mx) mx_str = min(str,mx_str);
        else if(sum > mx){mx = sum; mx_str = str;}
    }
    cout << mx_str;

    return 0;
}