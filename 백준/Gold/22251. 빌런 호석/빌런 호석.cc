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

void dfs(int dep, int sum, string s)
{
    if(dep == k){
        int temp = stoi(s);
        if(s == x) return;
        if(1 <= temp && temp <= stoi(n)){
            // cout << s << " " << x << "\n";
            ans++;
        }
    }
    else{
        int temp = x[dep] - '0';
        for(int i=0;i<10;i++){
            char c = '0'+i;
            if(sum - dif_cnt[temp][i] >= 0) dfs(dep+1, sum-dif_cnt[temp][i], s+c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            dif(i, j);

    cin >> n >> k >> p >> x;
    int nsize = n.size(), xsize = x.size();  // 따로 저장을 안하고 하니 아래 for문에서 x.size()로 넣어서 하니 반복 중에 x의 크기가 증가해서 이상해짐.
    for (int i = 0; i < k - nsize; i++)
        n = '0' + n; 
    for (int i = 0; i < k - xsize; i++)
        x = '0' + x;
    
    dfs(0, p, "");

    cout << ans;

    return 0;
}