#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b;
    cin >> a >> b;
    int cnt = a;
    while(!(a%cnt==0 && b%cnt==0)) cnt--;
    cout << cnt << "\n" << a*b/cnt;

    return 0;
}