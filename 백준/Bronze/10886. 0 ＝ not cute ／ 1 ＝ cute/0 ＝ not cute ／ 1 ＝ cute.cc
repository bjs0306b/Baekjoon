#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int m = n;
    int sum = 0;
    while(n--){int num; cin >> num; sum += num;}
    if(m/2 < sum) cout << "Junhee is cute!";
    else cout << "Junhee is not cute!";
    
    return 0;
}