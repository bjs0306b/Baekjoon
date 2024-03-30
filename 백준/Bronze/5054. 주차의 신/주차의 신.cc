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
    int n; cin >> n;
    while(n--){
        int num; cin >> num;
        int arr[num]; for(int i = 0; i < num; i++) cin >> arr[i];
        sort(arr, arr + num);
        cout << 2 * (arr[num - 1] - arr[0]) << '\n';
    }
    
    return 0;
}