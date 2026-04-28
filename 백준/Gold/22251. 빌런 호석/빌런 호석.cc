#include <bits/stdc++.h>
using namespace std;
int k, p, ans;
string n, x;
int arr[6];
bool nums[10][7] = {
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}};
int dif_cnt[10][10];

void dif(int a, int b)
{
    int cnt = 0;
    for (int i = 0; i < 7; i++)
    {
        if (nums[a][i] != nums[b][i])
            cnt++;
    }
    dif_cnt[a][b] = cnt;
}

void func(string a){
    int temp = k - a.size();
    for(int i=0;i<temp;i++) a = '0' + a;

    int sum = 0;
    for(int i=0;i<a.size();i++){
        sum += dif_cnt[x[i]-'0'][a[i]-'0'];
    }
    if(sum <= p) ans++;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            dif(i, j);

    cin >> n >> k >> p >> x;
    
    int xsize = x.size();
    for(int i=0;i<k-xsize;i++) x = '0' + x;
    for(int i=1;i<=stoi(n);i++){
        if(stoi(x) != i) func(to_string(i));
    }

    cout << ans;

    return 0;
}