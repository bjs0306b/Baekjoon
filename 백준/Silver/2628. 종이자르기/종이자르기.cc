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
    int a,b; cin >> a >> b;
    bool arr[a*2], arr2[b*2]; memset(arr, false, 2*a); memset(arr2, false, 2*b); arr[a*2-1] = true; arr2[b*2-1] = true;
    int num; cin >> num;
    for(int i=0;i<num;i++){
        int m,n; cin >> m >> n;
        if(m)
            arr[n*2-1] = true;
        else arr2[n*2-1] = true;
    }
    int maxa=0, maxb=0;
    int sum = 0;
    for(int i=0;i<a*2;i++){
        if(!arr[i]) sum++;
        else{
            int temp = (sum+1)/2;
            if(maxa < temp) maxa = temp;
            sum = 0;
        }
    }
    for(int i=0;i<b*2;i++){
        if(!arr2[i]) sum++;
        else{
            int temp = (sum+1)/2;
            if(maxb < temp) maxb = temp;
            sum = 0;
        }
    }
    cout << maxa*maxb;
    return 0;
}