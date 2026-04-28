// 반례 참조 https://www.acmicpc.net/board/view/107419
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n;
    deque<string> deq;
    cin >> n;
    int pre=0,now=0, imax = 0;
    for(int i=0;i<n;i++){
        pre = now;
        cin >> now;

        if(imax > now && imax > pre && now > pre){
            cout << "NO";
            return 0;
        }
        if(now == 1 && imax > 0){
            if((imax-1) != count(deq.begin(), deq.end(), "-")){
                cout << "NO"; return 0;
            }
        }
        if(now > imax){
            for(int i =0; i<(now-imax);i++) deq.push_back("+");
            deq.push_back("-");
            imax = now;
            continue;
        } 
        if(now < pre) deq.push_back("-");
    }
    for(int i=0;i<2*n;i++){ cout << deq.front() << "\n"; deq.pop_front();}

    return 0;
}