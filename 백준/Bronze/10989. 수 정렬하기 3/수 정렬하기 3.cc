#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, num, i,j;
    int arr[10001];
    cin >> n;
    for(i=0;i<10001;i++) arr[i]=0;
    for(i=0;i<n;i++){
        cin >> num;
        arr[num]++;
    }
    for(i=0;i<10001;i++)
        if(arr[i])
            for(j=0;j<arr[i];j++)
                cout << i << "\n";
    
    return 0;
}