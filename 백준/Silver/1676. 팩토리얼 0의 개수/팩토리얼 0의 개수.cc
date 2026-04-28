#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i=1;i<n+1;i++){
        int temp = i;
        while(temp % 5 == 0){
            cnt++;
            temp /= 5;
        }
    }

    cout << cnt;
}

