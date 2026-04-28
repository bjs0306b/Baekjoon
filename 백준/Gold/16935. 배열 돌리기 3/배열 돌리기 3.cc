#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int A[100][100];
bool flag; // false 회전 안함, true 회전함.

vector<int> v;
void input()
{
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    v.resize(r);
    for (int i = 0; i < r; i++)
        cin >> v[i];
}

void change_1()
{
    int temp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[i][j] = A[n - i - 1][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = temp[i][j];
        }
    }
}
void change_2()
{
    int temp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[i][j] = A[i][m - j - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = temp[i][j];
        }
    }
}
void change_3()
{
    int temp[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[j][n - 1 - i] = A[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = temp[i][j];
        }
    }

    swap(n,m);
}
void change_4()
{
    int temp[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[m-1-j][i] = A[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = temp[i][j];
        }
    }

    swap(n,m);
}
void change_5()
{
    int s_x[] = {0,0,n/2,n/2}, s_y[] = {0,m/2,m/2,0};
    int temp[4][n/2][m/2];
    for(int i=0;i<4;i++){
        for(int j=0;j<n/2;j++){
            for(int k=0;k<m/2;k++){
                temp[i][j][k] = A[s_x[i]+j][s_y[i]+k];
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<n/2;j++){
            for(int k=0;k<m/2;k++){
                A[s_x[(i+1)%4] + j][s_y[(i+1)%4] + k] = temp[i][j][k];
            }
        }
    }
}
void change_6()
{
    int s_x[] = {0,0,n/2,n/2}, s_y[] = {0,m/2,m/2,0};
    int temp[4][n/2][m/2];
    for(int i=0;i<4;i++){
        for(int j=0;j<n/2;j++){
            for(int k=0;k<m/2;k++){
                temp[i][j][k] = A[s_x[i]+j][s_y[i]+k];
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<n/2;j++){
            for(int k=0;k<m/2;k++){
                A[s_x[(i+3)%4] + j][s_y[(i+3)%4] + k] = temp[i][j][k];
            }
        }
    }
}

void solve()
{
    for (int i = 0; i < r; i++)
    {
        switch (v[i])
        {
        case 1:
        {
            change_1();
            break;
        }
        case 2:
        {
            change_2();
            break;
        }
        case 3:
        {
            change_3();
            break;
        }
        case 4:
        {
            change_4();
            break;
        }
        case 5:
        {
            change_5();
            break;
        }
        case 6:
        {
            change_6();
            break;
        }
        }
    } 
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }  
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    input();
    solve();

    return 0;
}