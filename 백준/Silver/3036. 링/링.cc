#include <iostream>
#include <algorithm>
using namespace std;

void giyak(int a, int b){
    int i,t = max(a,b);
    for(i=t;i>0 && a%i || b%i;i--);
    cout << a/i << "/" << b/i << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int arr[n]; for(int i=0;i<n;i++)  cin >> arr[i];
    for(int i=1;i<n;i++){
        giyak(arr[0], arr[i]);
    }
    
    return 0;
}