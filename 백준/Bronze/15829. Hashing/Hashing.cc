    #include <iostream>
    #include <algorithm>
    using namespace std;

    int main(){
        ios_base::sync_with_stdio(0);cin.tie(0);
        long n;
        cin >> n;
        long r = 1;
        long total=0;
        for(long i=0;i<n;i++)
        {
            char c;
            cin >> c;
            long m = c - 'a' + 1;
            total += r*m ;
            r = (r*31)% 1234567891;
        }
        cout << total % 1234567891;
        
        return 0;
    }