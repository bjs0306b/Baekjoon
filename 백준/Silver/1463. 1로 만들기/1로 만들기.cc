#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int arr[n+1]; for(int i=1;i<n+1;i++) arr[i]=0;
    arr[1] = 0; arr[2] = 1; arr[3] = 1;
    int i=4;
    while(i <= n){
        int a = INT32_MAX, b = INT32_MAX, c = INT32_MAX;
        a = arr[i-1];
        if(i%2==0) b = arr[i/2];
        if(i%3==0) c = arr[i/3];
        arr[i] = min({a,b,c})+1;
        i++;
    }
    cout << arr[n];    
    return 0;
}