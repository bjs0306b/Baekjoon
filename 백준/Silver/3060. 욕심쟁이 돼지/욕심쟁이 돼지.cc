#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    while(n--){
        long long day = 1;
        long long feed; cin >> feed;
        vector<long long> pig(6); for(long long i=0;i<6;i++) cin >> pig[i];

        for(;;){
            long long sum = 0;
            for(long long i=0;i<6;i++){
                sum += pig[i];
            }
            if(sum > feed){
                cout << day << '\n';
                break;
            }

            vector<long long> add(6);
            for(long long i=0;i<6;i++){
                add[i] = pig[(i+1)%6]+pig[(i+5)%6]+pig[(i+3)%6];
            }
            for(long long i=0;i<6;i++) pig[i] += add[i];

            day++;
        }
    }

    return 0;
}