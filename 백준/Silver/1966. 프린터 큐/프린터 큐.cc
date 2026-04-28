#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

class node
{
public:
    int num;
    int check;
    node() {}
    node(int c, int n) : check(c), num(n) {}
};
int maxmax(deque<node> d){
    int max=0;
    for(auto a: d){
        if(a.num > max) max = a.num;
    }
    return max;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        deque<node> d;
        int a, b, cnt=0;
        cin >> a >> b;
        int arr[a];
        for (int j = 0; j < a; j++)
        {
            int num;
            cin >> num;
            if(j == b) d.push_back(node(1,num));
            else d.push_back(node(0,num));
        }
        for(;;){
            if(d.front().num == maxmax(d)){
                if(d.front().check == 1) {cnt++; break;}
                else {cnt++; d.pop_front();}
            } 
            else{
                node temp = d.front();
                d.pop_front();
                d.push_back(temp);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}