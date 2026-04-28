#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    for(;;){
        vector<int> v;
        int sum=0;
        cin >> n; if(n == -1) break;
        for(int i=1;i<n;i++){
            if(n%i==0){
                sum += i;
                v.push_back(i);
            }
        }
        if(sum == n){
            cout << n << " = ";
            for(int i=0;i<v.size()-1;i++){
                cout << v[i] << " + ";
            }
            cout << v[v.size()-1] << "\n";
        }
        else{
            cout << n << " is NOT perfect.\n";
        }
    }
    
    
    return 0;
}