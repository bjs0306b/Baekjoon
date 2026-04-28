    #include <iostream>
    #include <algorithm>
    using namespace std;

    int main(){
        ios_base::sync_with_stdio(0);cin.tie(0);
        long long n;
        cin >> n;
        for(long long i=0;i<n;i++){
            long long a,b,ans=1; cin >>a>>b;
            a = max(a,b-a);
            for(int j=1;j<a+1;j++){
                ans = ans * (b-j+1) / j;
            }
            cout << ans <<"\n";
        }
        
        return 0;
    }