// 에라토스 테네스의 체 참고함.
#include <iostream>
#include <algorithm>
#include <deque>
#include <math.h>
using namespace std;

int sosu(int num){
    for(int i=2;i<num;i++)
        if(num%i==0) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m, n;
    cin >> m >> n;
    deque<int> deque1;
    deque1.push_back(2);
    for(int i=3;i<sqrt(n)+1;i++){
        if(sosu(i)) deque1.push_back(i);
    }
    int arr[n+1];
    for(int i=2;i<n+1;i++) arr[i]=1;

    while(!deque1.empty()){
        int temp = deque1.front();
        deque1.pop_front();
        for(int i=temp*2;i<n+1;i+=temp)
            arr[i] = 0;
    }
    for(int i=m;i<n+1;i++)
        if(arr[i]) 
            cout << i << "\n";   
    
    return 0;
}