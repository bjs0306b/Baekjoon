#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<9;i++){
        int num; cin>>num; n-=num;
    }
    cout << n;
    return 0;
}