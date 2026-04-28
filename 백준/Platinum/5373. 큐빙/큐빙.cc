#include <bits/stdc++.h>
using namespace std;

char A[6][3][3];
char color[6] = {'o', 'w', 'r', 'y', 'g', 'b'};

void solve()
{
    char copy[6][3][3];
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                copy[i][j][k] = A[i][j][k];
    int n;
    cin >> n;
    char a, b;
    for (int l = 0; l < n; l++)
    {
        // cout << "step " << l + 1 << "\n";
        cin >> a >> b;

        switch (a)
        {
        case 'U':
        {
            if (b == '+')
            {
                char temp[3] = {copy[0][2][0], copy[0][2][1], copy[0][2][2]};

                for (int i = 0; i < 3; i++)
                    copy[0][2][i] = copy[4][2 - i][2];
                for (int i = 0; i < 3; i++)
                    copy[4][i][2] = copy[2][0][i];
                for (int i = 0; i < 3; i++)
                    copy[2][0][i] = copy[5][2 - i][0];
                for (int i = 0; i < 3; i++)
                    copy[5][i][0] = temp[i];

                char temp2[4][3] = {{copy[1][0][0], copy[1][0][1], copy[1][0][2]},
                                    {copy[1][0][2], copy[1][1][2], copy[1][2][2]},
                                    {copy[1][2][2], copy[1][2][1], copy[1][2][0]},
                                    {copy[1][2][0], copy[1][1][0], copy[1][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[1][i][2] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[1][2][2 - i] = temp2[1][i];
                for (int i = 0; i < 3; i++)
                    copy[1][2 - i][0] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[1][0][i] = temp2[3][i];
            }
            else
            {
                char temp[3] = {copy[0][2][0], copy[0][2][1], copy[0][2][2]};

                for (int i = 0; i < 3; i++)
                    copy[0][2][i] = copy[5][i][0];
                for (int i = 0; i < 3; i++)
                    copy[5][2 - i][0] = copy[2][0][i];
                for (int i = 0; i < 3; i++)
                    copy[2][0][i] = copy[4][i][2];
                for (int i = 0; i < 3; i++)
                    copy[4][2 - i][2] = temp[i];

                char temp2[4][3] = {{copy[1][0][0], copy[1][0][1], copy[1][0][2]},
                                    {copy[1][0][2], copy[1][1][2], copy[1][2][2]},
                                    {copy[1][2][2], copy[1][2][1], copy[1][2][0]},
                                    {copy[1][2][0], copy[1][1][0], copy[1][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[1][i][2] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[1][2][2 - i] = temp2[3][i];
                for (int i = 0; i < 3; i++)
                    copy[1][2 - i][0] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[1][0][i] = temp2[1][i];
            }
            break;
        }
        case 'D':
        {
            if (b == '+')
            {
                char temp[3] = {copy[0][0][0], copy[0][0][1], copy[0][0][2]};
                for (int i = 0; i < 3; i++)
                    copy[0][0][i] = copy[5][i][2];
                for (int i = 0; i < 3; i++)
                    copy[5][2 - i][2] = copy[2][2][i];
                for (int i = 0; i < 3; i++)
                    copy[2][2][i] = copy[4][i][0];
                for (int i = 0; i < 3; i++)
                    copy[4][2 - i][0] = temp[i];

                char temp2[4][3] = {{copy[3][0][0], copy[3][0][1], copy[3][0][2]},
                                    {copy[3][0][2], copy[3][1][2], copy[3][2][2]},
                                    {copy[3][2][2], copy[3][2][1], copy[3][2][0]},
                                    {copy[3][2][0], copy[3][1][0], copy[3][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[3][i][2] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[3][2][2 - i] = temp2[1][i];
                for (int i = 0; i < 3; i++)
                    copy[3][2 - i][0] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[3][0][i] = temp2[3][i];
            }
            else
            {
                char temp[3] = {copy[0][0][0], copy[0][0][1], copy[0][0][2]};
                for (int i = 0; i < 3; i++)
                    copy[0][0][i] = copy[4][2 - i][0];
                for (int i = 0; i < 3; i++)
                    copy[4][i][0] = copy[2][2][i];
                for (int i = 0; i < 3; i++)
                    copy[2][2][i] = copy[5][2 - i][2];
                for (int i = 0; i < 3; i++)
                    copy[5][i][2] = temp[i];

                char temp2[4][3] = {{copy[3][0][0], copy[3][0][1], copy[3][0][2]},
                                    {copy[3][0][2], copy[3][1][2], copy[3][2][2]},
                                    {copy[3][2][2], copy[3][2][1], copy[3][2][0]},
                                    {copy[3][2][0], copy[3][1][0], copy[3][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[3][i][2] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[3][2][2 - i] = temp2[3][i];
                for (int i = 0; i < 3; i++)
                    copy[3][2 - i][0] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[3][0][i] = temp2[1][i];
            }
            break;
        }
        case 'F':
        {
            if (b == '+')
            {
                char temp[3] = {copy[1][2][0], copy[1][2][1], copy[1][2][2]};

                for (int i = 0; i < 3; i++)
                    copy[1][2][i] = copy[4][2][i];
                for (int i = 0; i < 3; i++)
                    copy[4][2][i] = copy[3][0][2 - i];
                for (int i = 0; i < 3; i++)
                    copy[3][0][i] = copy[5][2][2 - i];
                for (int i = 0; i < 3; i++)
                    copy[5][2][i] = temp[i];

                char temp2[4][3] = {{copy[2][0][0], copy[2][0][1], copy[2][0][2]},
                                    {copy[2][0][2], copy[2][1][2], copy[2][2][2]},
                                    {copy[2][2][2], copy[2][2][1], copy[2][2][0]},
                                    {copy[2][2][0], copy[2][1][0], copy[2][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[2][i][2] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[2][2][2 - i] = temp2[1][i];
                for (int i = 0; i < 3; i++)
                    copy[2][2 - i][0] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[2][0][i] = temp2[3][i];
            }
            else
            {
                char temp[3] = {copy[1][2][0], copy[1][2][1], copy[1][2][2]};
                for (int i = 0; i < 3; i++)
                    copy[1][2][i] = copy[5][2][i];
                for (int i = 0; i < 3; i++)
                    copy[5][2][2 - i] = copy[3][0][i];
                for (int i = 0; i < 3; i++)
                    copy[3][0][2 - i] = copy[4][2][i];
                for (int i = 0; i < 3; i++)
                    copy[4][2][i] = temp[i];

                char temp2[4][3] = {{copy[2][0][0], copy[2][0][1], copy[2][0][2]},
                                    {copy[2][0][2], copy[2][1][2], copy[2][2][2]},
                                    {copy[2][2][2], copy[2][2][1], copy[2][2][0]},
                                    {copy[2][2][0], copy[2][1][0], copy[2][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[2][i][2] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[2][2][2 - i] = temp2[3][i];
                for (int i = 0; i < 3; i++)
                    copy[2][2 - i][0] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[2][0][i] = temp2[1][i];
            }
            break;
        }
        case 'B':
        {
            if (b == '+')
            {
                char temp[3] = {copy[1][0][0], copy[1][0][1], copy[1][0][2]};
                for (int i = 0; i < 3; i++)
                    copy[1][0][i] = copy[5][0][i];
                for (int i = 0; i < 3; i++)
                    copy[5][0][2 - i] = copy[3][2][i];
                for (int i = 0; i < 3; i++)
                    copy[3][2][2 - i] = copy[4][0][i];
                for (int i = 0; i < 3; i++)
                    copy[4][0][i] = temp[i];

                char temp2[4][3] = {{copy[0][0][0], copy[0][0][1], copy[0][0][2]},
                                    {copy[0][0][2], copy[0][1][2], copy[0][2][2]},
                                    {copy[0][2][2], copy[0][2][1], copy[0][2][0]},
                                    {copy[0][2][0], copy[0][1][0], copy[0][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[0][i][2] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[0][2][2 - i] = temp2[1][i];
                for (int i = 0; i < 3; i++)
                    copy[0][2 - i][0] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[0][0][i] = temp2[3][i];
            }
            else
            {
                char temp[3] = {copy[1][0][0], copy[1][0][1], copy[1][0][2]};
                for (int i = 0; i < 3; i++)
                    copy[1][0][i] = copy[4][0][i];
                for (int i = 0; i < 3; i++)
                    copy[4][0][i] = copy[3][2][2 - i];
                for (int i = 0; i < 3; i++)
                    copy[3][2][i] = copy[5][0][2 - i];
                for (int i = 0; i < 3; i++)
                    copy[5][0][i] = temp[i];

                char temp2[4][3] = {{copy[0][0][0], copy[0][0][1], copy[0][0][2]},
                                    {copy[0][0][2], copy[0][1][2], copy[0][2][2]},
                                    {copy[0][2][2], copy[0][2][1], copy[0][2][0]},
                                    {copy[0][2][0], copy[0][1][0], copy[0][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[0][i][2] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[0][2][2 - i] = temp2[3][i];
                for (int i = 0; i < 3; i++)
                    copy[0][2 - i][0] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[0][0][i] = temp2[1][i];
            }
            break;
        }
        case 'L':
        {
            if (b == '+')
            {
                char temp[3] = {copy[1][0][0], copy[1][1][0], copy[1][2][0]};

                for (int i = 0; i < 3; i++)
                    copy[1][i][0] = copy[0][i][0];
                for (int i = 0; i < 3; i++)
                    copy[0][i][0] = copy[3][i][0];
                for (int i = 0; i < 3; i++)
                    copy[3][i][0] = copy[2][i][0];
                for (int i = 0; i < 3; i++)
                    copy[2][i][0] = temp[i];

                char temp2[4][3] = {{copy[4][0][0], copy[4][0][1], copy[4][0][2]},
                                    {copy[4][0][2], copy[4][1][2], copy[4][2][2]},
                                    {copy[4][2][2], copy[4][2][1], copy[4][2][0]},
                                    {copy[4][2][0], copy[4][1][0], copy[4][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[4][i][2] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[4][2][2 - i] = temp2[1][i];
                for (int i = 0; i < 3; i++)
                    copy[4][2 - i][0] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[4][0][i] = temp2[3][i];
            }
            else
            {
                char temp[3] = {copy[1][0][0], copy[1][1][0], copy[1][2][0]};
                for (int i = 0; i < 3; i++)
                    copy[1][i][0] = copy[2][i][0];
                for (int i = 0; i < 3; i++)
                    copy[2][i][0] = copy[3][i][0];
                for (int i = 0; i < 3; i++)
                    copy[3][i][0] = copy[0][i][0];
                for (int i = 0; i < 3; i++)
                    copy[0][i][0] = temp[i];

                char temp2[4][3] = {{copy[4][0][0], copy[4][0][1], copy[4][0][2]},
                                    {copy[4][0][2], copy[4][1][2], copy[4][2][2]},
                                    {copy[4][2][2], copy[4][2][1], copy[4][2][0]},
                                    {copy[4][2][0], copy[4][1][0], copy[4][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[4][i][2] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[4][2][2 - i] = temp2[3][i];
                for (int i = 0; i < 3; i++)
                    copy[4][2 - i][0] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[4][0][i] = temp2[1][i];
            }
            break;
        }
        case 'R':
        {
            if (b == '+')
            {
                char temp[3] = {copy[1][0][2], copy[1][1][2], copy[1][2][2]};
                for (int i = 0; i < 3; i++)
                    copy[1][i][2] = copy[2][i][2];
                for (int i = 0; i < 3; i++)
                    copy[2][i][2] = copy[3][i][2];
                for (int i = 0; i < 3; i++)
                    copy[3][i][2] = copy[0][i][2];
                for (int i = 0; i < 3; i++)
                    copy[0][i][2] = temp[i];

                char temp2[4][3] = {{copy[5][0][0], copy[5][0][1], copy[5][0][2]},
                                    {copy[5][0][2], copy[5][1][2], copy[5][2][2]},
                                    {copy[5][2][2], copy[5][2][1], copy[5][2][0]},
                                    {copy[5][2][0], copy[5][1][0], copy[5][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[5][i][2] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[5][2][2 - i] = temp2[1][i];
                for (int i = 0; i < 3; i++)
                    copy[5][2 - i][0] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[5][0][i] = temp2[3][i];
            }
            else
            {
                char temp[3] = {copy[1][0][2], copy[1][1][2], copy[1][2][2]};

                for (int i = 0; i < 3; i++)
                    copy[1][i][2] = copy[0][i][2];
                for (int i = 0; i < 3; i++)
                    copy[0][i][2] = copy[3][i][2];
                for (int i = 0; i < 3; i++)
                    copy[3][i][2] = copy[2][i][2];
                for (int i = 0; i < 3; i++)
                    copy[2][i][2] = temp[i];

                char temp2[4][3] = {{copy[5][0][0], copy[5][0][1], copy[5][0][2]},
                                    {copy[5][0][2], copy[5][1][2], copy[5][2][2]},
                                    {copy[5][2][2], copy[5][2][1], copy[5][2][0]},
                                    {copy[5][2][0], copy[5][1][0], copy[5][0][0]}};

                for (int i = 0; i < 3; i++)
                    copy[5][i][2] = temp2[2][i];
                for (int i = 0; i < 3; i++)
                    copy[5][2][2 - i] = temp2[3][i];
                for (int i = 0; i < 3; i++)
                    copy[5][2 - i][0] = temp2[0][i];
                for (int i = 0; i < 3; i++)
                    copy[5][0][i] = temp2[1][i];
            }
            break;
        }
        }
        // for (int k = 1; k < 6; k++)
        // {
        //     for (int i = 0; i < 3; i++)
        //     {
        //         for (int j = 0; j < 3; j++)
        //         {
        //             cout << copy[k][i][j];
        //         }
        //         cout << "\n";
        //     }
        //     cout << "\n";
        // }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << copy[1][i][j];
        }
        cout << "\n";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                A[i][j][k] = color[i];
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}