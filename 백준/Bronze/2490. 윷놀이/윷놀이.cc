#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    for(int i=0;i<3;i++){
        int arr[4]; for(int i=0;i<4;i++) cin >> arr[i];
        int cnt = count(arr, arr+4, 0);
        switch(cnt){
            case 0: cout << "E" << "\n"; break;
            case 1: cout << "A" << "\n"; break;
            case 2: cout << "B" << "\n"; break;
            case 3: cout << "C" << "\n"; break;
            case 4: cout << "D" << "\n"; break;
        }
    }
    return 0;
}