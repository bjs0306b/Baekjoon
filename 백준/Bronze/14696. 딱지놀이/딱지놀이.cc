#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool match(int a[], int b[])
{
    if (a[4] == b[4])
    {
        if (a[3] == b[3])
        {
            if (a[2] == b[2])
            {
                return a[1] > b[1];
            }
            return a[2] > b[2];
        }
        return a[3] > b[3];
    }
    return a[4] > b[4];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int arr[5], arr2[5];
        for (int j = 0; j < 5; j++)
        {
            arr[j] = 0;
            arr2[j] = 0;
        }
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int s;
            cin >> s;
            arr[s]++;
        }
        int num2;
        cin >> num2;
        for (int j = 0; j < num2; j++)
        {
            int s;
            cin >> s;
            arr2[s]++;
        }
        int check = 1;
        for(int j=1;j<5;j++){
            if(arr[j] != arr2[j]) check=0;
        }
        if(check) cout << "D\n";
        else{
            if(match(arr,arr2)) cout << "A\n";
            else cout << "B\n";
        }
    }

    return 0;
}