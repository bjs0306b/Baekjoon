#include <bits/stdc++.h>
#include<charconv>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;

    int sum = 0;
    for(int i=1;;i++){
        if(k > sum + i*9*pow(10,i-1)) sum += i*9*pow(10,i-1);
        else{
            string temp = "";
            for(int j=0;j<i-1;j++) temp += '9';
            int num;

        
            if(temp.size() > 0){
               auto result = from_chars(temp.data(), temp.data() + temp.size(), num);
            }
            else num = 0;
            num += (k-sum)/i;
            if((k-sum)%i){
                int rest = (k-sum)%i;
                num++;
                string s = to_string(num);
                if(num > n) cout << -1;
                else cout << s[rest-1];
            } 
            else{
                string s = to_string(num);
                if(num > n) cout << -1;
                else cout << s[s.size()-1];
            }

            return 0;
        }
    }

    return 0;
}