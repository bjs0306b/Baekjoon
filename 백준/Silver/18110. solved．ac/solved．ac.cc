#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;  
    cin >> n;
    deque<int> deq;
    int sum = 0;
    if(n != 0){
        for(int i=0;i<n;i++){
            int num;
            cin >> num;
            deq.push_back(num);
        }
        float cutt = 0.15*n;
        int cut = static_cast<int>(cutt+0.5);
        sort(deq.begin(), deq.end());
        for(int i = 0; i < cut; i++){
            deq.pop_back();
            deq.pop_front();
        }
        
        for(deque<int>::iterator iter = deq.begin(); iter != deq.end(); iter++){
            sum += *iter;
        }
        float averr = (float)sum / (float)(deq.size());
        int aver = static_cast<int>(averr+0.5);

        cout << aver;
    }
    else cout << 0;
    return 0;
}