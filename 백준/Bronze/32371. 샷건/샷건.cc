#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    char arr[40]; for(int i=0;i<40;i++) cin >> arr[i];

    // for(int i=0;i<40;i++) cout << arr[i] << " ";
    vector<int> v;
    for(int i=0;i<9;i++){
        char c; cin >> c;
        for(int j=0;j<40;j++){
            if(arr[j] == c) v.push_back(j);
        }
    }
    sort(v.begin(), v.end());

    cout << arr[v[4]];
    


    return 0;
}