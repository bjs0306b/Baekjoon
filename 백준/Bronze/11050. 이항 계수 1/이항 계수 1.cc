#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int a,b;
    cin >> a >> b;
    int num = 1;
    for(int i=a;i>a-b;i--) num *= i;
    for(int i=1;i<=b;i++) num /= i;

    cout << num;
    return 0;
}