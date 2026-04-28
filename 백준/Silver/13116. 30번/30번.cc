#include <bits/stdc++.h>
using namespace std;

void func(int a, int b){
    deque<int> d1,d2;
    while(a){
        d1.push_front(a);
        a/=2;
    }
    while(b){
        d2.push_front(b);
        b/=2;
    }

    for(auto riter = d1.rbegin(); riter != d1.rend(); riter++){
        if(find(d2.begin(), d2.end(), *riter) != d2.end()){
            cout << *riter*10 << "\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        func(a,b);
    }

    return 0;
}