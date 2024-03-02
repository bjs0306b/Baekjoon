#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a,b,sum=0; cin >>a>>b;
    char arr[b][a]; for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin >> arr[j][i];
    char answer[b];
    for(int i=0;i<b;i++){
        int cnt[4]; char temp[4] = {'A','C','G','T'};
        int sum_cnt=0;
        for(int j=0;j<4;j++) {cnt[j] = count(&arr[i][0], &arr[i][a], temp[j]); sum_cnt+=cnt[j];}
        auto iter = max_element(cnt,cnt+4);
        int pos = iter - cnt;
        sum += sum_cnt-cnt[pos];
        cout << temp[pos];
    }
    cout << "\n" << sum;
    
    
    return 0;
}