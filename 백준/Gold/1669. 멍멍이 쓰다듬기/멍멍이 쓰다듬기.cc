#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b; cin >> a >> b;
    int k = b-a;

    if(k == 0){
        cout << 0; return 0;
    }
    for(int i=1;;i++){
        if(k <= 2*i){
            if(k <= i)
                cout << 2*i-1;
            else cout << 2*i;
            return 0;
        }
        k -= 2*i;
    }

    return 0;
}