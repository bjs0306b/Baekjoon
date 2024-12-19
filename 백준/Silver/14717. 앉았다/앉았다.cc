#include <bits/stdc++.h>
using namespace std;

int score(int a, int b)
{
    if (a == b)
        return 9 + a;
    else
        return (a + b) % 10;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10};

    int a, b;
    cin >> a >> b;

    v.erase(find(v.begin(), v.end(), a));
    v.erase(find(v.begin(), v.end(), b));
    int my_score = score(a,b);

    int cnt = 0, win = 0;
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j<v.size();j++){
            if(my_score > score(v[i], v[j])) win++;
            cnt++;
        }
    }

    cout << fixed << setprecision(3);
    cout << double(win)/double(cnt);

        return 0;
}