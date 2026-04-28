#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    double arr[n]; 
    for(int i=0;i<n;i++)
        cin >> arr[i];
    double mx = 0;
    for(int i=0;i<n;i++){   
        double temp = arr[i];
        mx = max(mx, temp);
        for(int j=i+1;j<=n;j++){
            temp *= arr[j];
            mx = max(mx, temp);
        }
    }
    printf("%.3lf", mx);
    return 0;
}   