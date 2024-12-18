#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    cin.ignore();
    for(int i=1;i<=n;i++){
        string s; getline(cin, s);

        vector<int> v(26);
        for(auto k : s){
           if(k >= 'a' && k <= 'z'){
             int num = k - 'a';
             v[num]++;
           }
           else if(k >= 'A' && k <= 'Z'){
             int num = k - 'A';
             v[num]++;
           }
        }

        int mn = INT32_MAX;
        for(auto k : v){
            mn = min(mn, k);
        }
        
        cout << "Case " << i << ": ";
        if(mn == 0) cout << "Not a pangram\n";
        else if(mn == 1) cout << "Pangram!\n";
        else if(mn == 2) cout << "Double pangram!!\n";
        else cout << "Triple pangram!!!\n";
    }

    return 0;
}