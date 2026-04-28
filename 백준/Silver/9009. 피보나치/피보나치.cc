#include <bits/stdc++.h>
using namespace std;

int fibo[44];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    fibo[0] = 1, fibo[1] = 1;
    for(int i=2;i<44;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    for(int i=0;i<n;i++){
        int num; cin >> num;
        vector<int> v;
        for(int j=43;j>=0;j--){
            if(num >= fibo[j]){
                num -= fibo[j];
                v.push_back(fibo[j]);
            }
        }
        sort(v.begin(), v.end());

        for(int i=0;i<v.size();i++) cout << v[i] << " ";
        cout << "\n";
    }


    return 0;
}