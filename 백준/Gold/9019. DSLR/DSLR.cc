#include<bits/stdc++.h>
using namespace std;

struct tmp{
    int num;
    string str;
};

int left(int n){
    int temp = n / 1000;
    n = (n % 1000) * 10 + temp;
    return n;
}

int right(int n){
    int temp = n % 10;
    n -= temp;
    n /= 10;
    n += temp * 1000;
    return n;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++){
        bool arr[10000]; memset(arr, 0, 10000);
        queue<tmp> q;
        int a,b; cin >> a >> b;
        q.push({a,""});
        arr[a] = 1;
        for(;;){
            tmp temp = q.front();
            q.pop();
            int qnum = temp.num;

            if(qnum == b){cout << temp.str << "\n"; break;}

            if(!arr[(qnum+9999)%10000]){
                arr[(qnum+9999)%10000] = 1;
                q.push({(qnum+9999)%10000, temp.str + 'S'});
            }

            if(!arr[left(qnum)]){
                arr[left(qnum)] = 1;
                q.push({left(qnum), temp.str + 'L'});
            }

            if(!arr[right(qnum)]){
                arr[right(qnum)] = 1;
                q.push({right(qnum), temp.str + 'R'});
            }

            if(!arr[(qnum*2)%10000]){
                arr[(qnum*2)%10000] = 1;
                q.push({(qnum*2)%10000, temp.str + 'D'});
            }
        }
    }
    
    return 0;
}