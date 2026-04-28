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
    int a,b; cin >> a >> b;
    int arr[a][b],sum=0;
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++){
            string num; cin >> num;
            arr[i][j] = count(num.begin(),num.end(),'9');
            sum += arr[i][j];
        }
    int mx = 0;
    
    for(int i=0;i<a;i++){
        int sm = 0;
        for(int j=0;j<b;j++)
            sm += arr[i][j];
        mx = max(mx,sm);
    }

    for(int i=0;i<b;i++){
        int sm = 0;
        for(int j=0;j<a;j++)
            sm += arr[j][i];
        mx = max(mx,sm);
    }

    cout << sum-mx;
    return 0;
}