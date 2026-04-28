#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        string arr[num]; for(int j=0;j<num;j++) cin >> arr[j];
        bool flag = false;
        for(int j=0;j<num-1;j++){
            for(int k=j+1;k<num;k++){
                string temp = arr[j] + arr[k];
                string rev = temp;
                reverse(temp.begin(), temp.end());
                if(temp == rev){cout << temp << "\n"; flag = true; break;}

                temp = arr[k] + arr[j];
                rev = temp;
                reverse(temp.begin(), temp.end());
                if(temp == rev){cout << temp << "\n"; flag = true; break;}
            }
            if(flag) break;
        }
        if(!flag) cout << 0 << "\n";
    }
    
    return 0;
}