#include <bits/stdc++.h>
using namespace std;
int s,e; 
bool visited[200001];
int pre_visited_num[200001];
int ttime = 0;
void print_ans(int num){
    if(num == s){
        cout << ttime << "\n" << s << " ";
        return;
    }
    else{
        print_ans(pre_visited_num[num]);
        cout << num << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    cin >> s >> e;
    q.push(s);
    visited[s] = 1;

    if(s==e){
        cout << "0\n" << s;
        return 0;
    }
    else if(s > e){
        cout << s-e << "\n";
        for(int i = s; i>=e;i--) cout << i << " ";
        return 0;
    }
 
    for(;;){
        ttime++;
        int size = q.size();
        for(int i=0;i<size;i++){
            int f = q.front(); q.pop();

            if(!visited[f+1]){
                q.push(f+1);
                pre_visited_num[f+1] = f;
                visited[f+1] = true;

                if(f+1 == e){
                    print_ans(e);
                    return 0;
                }
            }
            if(f > 0 && !visited[f-1]){
                q.push(f-1);
                pre_visited_num[f-1] = f;
                visited[f-1] = true;

                if(f-1 == e){
                    print_ans(e);
                    return 0;
                }
            }
            if(f < 100000 && !visited[2*f]){
                q.push(2*f);
                pre_visited_num[2*f] = f;
                visited[2*f] = true;

                if(2*f == e){
                    print_ans(e);
                    return 0;
                }
            }
        }
    }

    return 0;
}