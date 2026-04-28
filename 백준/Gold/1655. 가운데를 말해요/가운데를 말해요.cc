#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int num; cin >> num;
    multiset<int> s; s.insert(num);
    auto iter = s.begin();
    cout << num << "\n";
    for (int i = 0; i < n - 1; i++)
    {
        cin >> num;
        s.insert(num);
        if(s.size() % 2 == 0){
            if(*iter > num) iter--;
        }
        else{
            if(*iter <= num) iter++;
        }
        cout << *iter << "\n";
    }

    return 0;
}