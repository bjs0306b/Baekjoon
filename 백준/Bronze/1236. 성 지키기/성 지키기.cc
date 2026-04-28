#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b; cin >>a>>b;
    int arr[a], arr2[b];
    for(int i=0;i<a;i++) arr[i]=0;
    for(int i=0;i<b;i++) arr2[i]=0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            char c;
            cin >> c;
            if (c == 'X')
                arr[i] = 1, arr2[j] = 1;
        }
    }
    int cnt=max(count(arr,arr+a, 0),count(arr2,arr2+b,0));

    cout << cnt;
    return 0;
}