#include <iostream>
#include <string>
using namespace std;

class queuetype{
public:
    int a[10001], front = 0, back = 0;
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    queuetype q;
    for(int i=0;i<n;i++){
        string commend;
        cin >> commend;
        if(commend == "push_front"){
            int num;
            cin >> num;
            q.a[q.front] = num;
            q.front = (q.front+10000)%10001;
        }
        else if(commend == "push_back"){
            int num;
            cin >> num;
            q.back = (q.back + 1)%10001;
            q.a[q.back] = num;
        }
        else if(commend == "pop_front"){
            if(q.front == q.back) cout << "-1" << "\n";
            else {
                q.front = (q.front + 1)%10001;
                cout << q.a[q.front] << "\n";
            }
        }
        else if(commend == "pop_back"){
            if(q.front == q.back) cout << "-1" << "\n";
            else {
                cout << q.a[q.back] << "\n";
                q.back = (q.back + 10000)%10001;
            }
        }
        else if(commend == "size"){
            cout << (q.back - q.front + 10001)%10001 << "\n";
        }
        else if(commend == "empty"){
            cout << (q.front == q.back) << "\n";
        }
        else if(commend == "front"){
            if(q.front == q.back) cout << "-1" << "\n";
            else cout << q.a[(q.front+1)%10001] << "\n"; 
        }
        else if(commend == "back"){
            if(q.front == q.back) cout << "-1" << "\n";
            else cout << q.a[q.back] << "\n";
        }
        else return 0;
    }
    return 0;
}