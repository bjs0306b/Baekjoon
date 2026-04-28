#include <iostream>
#include <algorithm>
using namespace std;

int m, n, arr[100010];

void binaryfind(int key){
    int s, e, mid;
    s = 0;
    e = m-1;
    
    while(e >= s){
        mid = (s+e)/2;
        if(arr[mid] == key){
            cout << 1 << "\n";
            return;
        }
        else if(arr[mid] > key) e = mid - 1;
        else s = mid + 1; 
    }
    cout << 0 << "\n";
    return;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> m;
    for( int i=0;i<m;i++) cin >> arr[i];
    cin >> n;
    sort(arr, arr+m);
    for( int i=0;i<n;i++){
        int num;
        cin >> num;
        binaryfind(num);
    }
    return 0;
}