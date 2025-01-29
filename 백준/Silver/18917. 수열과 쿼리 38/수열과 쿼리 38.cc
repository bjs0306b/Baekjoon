#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    long long xor_num = 0, sum = 0; 
    while (n--) {
        long long query; 
        cin >> query;
        if (query == 1) {
            long long num; 
            cin >> num;
            sum += num;
            xor_num ^= num;
        }
        else if (query == 2) {
            long long num; 
            cin >> num;
            sum -= num;
            xor_num ^= num;
        }
        else if (query == 3) {
            cout << sum << '\n';
        }
        else if (query == 4) {
            cout << xor_num << '\n';
        }
    }

    return 0;
}