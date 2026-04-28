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
        if(commend == "push"){
            int num;
            cin >> num;
            q.a[q.back++] = num;
        }
        else if(commend == "pop"){
            if(q.front == q.back) cout << "-1" << "\n";
            else cout << q.a[q.front++] << "\n";
        }
        else if(commend == "size"){
            cout << -q.front + q.back << "\n";
        }
        else if(commend == "empty"){
            cout << (q.front == q.back) << "\n";
        }
        else if(commend == "front"){
            if(q.front == q.back) cout << "-1" << "\n";
            else cout << q.a[q.front] << "\n"; 
        }
        else if(commend == "back"){
            if(q.front == q.back) cout << "-1" << "\n";
            else cout << q.a[q.back - 1] << "\n";
        }
        else return 0;
    }
    return 0;
}