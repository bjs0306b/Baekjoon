#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin >> n >> k;
    vector<int> gift_size(n); for(int i=0;i<n;i++) cin >> gift_size[i];
    vector<int> giftbox_size(n); for(int i=0;i<n;i++) cin >> giftbox_size[i];
    sort(gift_size.begin(), gift_size.end());
    sort(giftbox_size.begin(), giftbox_size.end());

    vector<int> pickers(k); for(int i=0;i<k;i++) cin >> pickers[i];
    sort(pickers.begin(), pickers.end());
    
    int i=n-1;
    for(int j=k-1;i>=0,j>=0;i--,j--){
        if(pickers[j] != giftbox_size[i]) break;
    }


    int temp = giftbox_size[i];

    auto iter = upper_bound(gift_size.begin(), gift_size.end(), temp);
    cout << *(iter-1);


    return 0;
}