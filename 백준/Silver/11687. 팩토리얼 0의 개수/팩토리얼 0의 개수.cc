#include <bits/stdc++.h>
using namespace std;

int func2(int n){
    int ret = 0;
    int temp = 5;
    while(n/temp){
        ret += n/temp;
        temp *= 5;
    }
    return ret;
}

int func(int n){
    
    int s = 1, e = n;
    while(s <= e){
        int m = (s+e)/2;

        if(n == func2(5*m)) return m*5;
        else if(n > func2(5*m)) s = m+1;
        else e = m-1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    cout << func(n);

    return 0;
}