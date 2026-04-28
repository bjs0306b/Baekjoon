#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n; cin >> n; long long arr[n];
    for(long long i=0;i<n;i++) cin >> arr[i];
    long long sum = 0;
    for(long long i=0;i<n-1;i++){
        for(long long j=i+1;j<n;j++){
            sum += abs(2*(arr[i]-arr[j]));
        }
    }
    cout << sum;
    
    return 0;
}