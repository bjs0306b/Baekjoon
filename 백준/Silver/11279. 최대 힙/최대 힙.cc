#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> qq;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        if(num == 0){
            if(qq.size()){
                cout << qq.top() << "\n";
                qq.pop();
            }
            else cout << "0\n";
        }
        else{
            qq.push(num);
        }
    }
    
    return 0;
}