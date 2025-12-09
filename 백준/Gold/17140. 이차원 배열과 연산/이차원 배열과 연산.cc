#include <bits/stdc++.h>
using namespace std;

struct node{
    int num, cnt;

    bool operator<(const node& other){
        if(cnt == other.cnt) return num < other.num;
        return cnt < other.cnt;
    }
};

int A[100][100];
int r,c,k; 
int r_size = 3, c_size = 3;
map<int,int> m;
vector<node> v;

void r_oper(){
    int mx = 0;
    for(int i=0;i<r_size;i++){
        m.clear();
        v.clear();
        for(int j=0;j<c_size;j++){
            if(A[i][j] == 0) continue;
                m[A[i][j]]++;
        }

        for(auto k : m){
            v.push_back({k.first, k.second});
            if(v.size() == 50) break;
        }

        sort(v.begin(), v.end());

        int size = v.size();
        mx = max(mx, size*2);

        for(int j=0;j<v.size();j++){
            A[i][j*2] = v[j].num;
            A[i][j*2+1] = v[j].cnt;
        }
        for(int j=v.size()*2;j<100;j++) A[i][j] = 0;
    }
    c_size = mx;
}

void c_oper(){
    int mx = 0;
    for(int i=0;i<c_size;i++){
        m.clear();
        v.clear();
        for(int j=0;j<r_size;j++){
            if(A[j][i] == 0) continue;
                m[A[j][i]]++;
        }

        for(auto k : m){
            v.push_back({k.first, k.second});
            if(v.size() == 50) break;
        }

        sort(v.begin(), v.end());

        int size = v.size();
        mx = max(mx, size*2);

        for(int j=0;j<v.size();j++){
            A[j*2][i] = v[j].num;
            A[j*2+1][i] = v[j].cnt;
        }
        for(int j=v.size()*2;j<100;j++) A[j][i] = 0;
    }
    r_size = mx;
}

void sort_func(){
    if(r_size >= c_size) // R 연산
    {
        r_oper();
    }
    else // C 연산
    {
        c_oper();
    }
}

void print(){
    cout << "r_size : " << r_size << "\n";
    cout << "c_size : " << c_size << "\n";
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int solve(){
    for(int i=0;i<=100;i++){
        // print();
        if(A[r-1][c-1] == k) return i;
        sort_func();
    }
    return -1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> r >> c >> k;

    for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin >> A[i][j];

    cout << solve();  

    return 0;
}