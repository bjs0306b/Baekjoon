#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <vector>
#include <deque>
#include <set>
#include <cmath>
using namespace std;
int arr[10][10][10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < 10; i++)
        for (int j = 1; j < 10; j++)
            for (int k = 1; k < 10; k++)
                if (i != j && j != k && k != i)
                    arr[i][j][k] = 1;

    while (n--)
    {
        string a;
        int b, c;
        cin >> a >> b >> c;
        int hund = a[0] - '0', ten = a[1] - '0', one = a[2] - '0';
        if (b == 0)
        {
            if (c == 0)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            if (arr[i][j][k])
                            {
                                if (!((i != hund && i != ten && i != one) && (j != hund && j != ten && j != one) && (k != hund && k != ten && k != one)))
                                {
                                    arr[i][j][k] = 0;
                                }
                            }
                        }
                    }
                }
            }
            else if (c == 1)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            if (arr[i][j][k])
                            {
                                if (!((((i == ten || i == one) && (j != hund && j != ten && j != one) && (k != hund && k != ten && k != one)) ||
                                       ((j == hund || j == one) && (i != hund && i != ten && i != one) && (k != hund && k != ten && k != one)) ||
                                       ((k == hund || k == ten) && (i != hund && i != ten && i != one) && (j != hund && j != ten && j != one)))))
                                {
                                    arr[i][j][k] = 0;
                                }
                            }
                        }
                    }
                }
            }
            else if (c == 2)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            if (arr[i][j][k])
                            {
                                if (!((((i == ten || i == one) && (j == one || j == hund)) && (k != hund && k != ten && k != one)) ||
                                      (((k == ten || k == hund) && (j == one || j == hund)) && (i != hund && i != ten && i != one)) ||
                                      (((i == ten || i == one) && (k == ten || k == hund)) && (j != hund && j != ten && j != one))))
                                {
                                    arr[i][j][k] = 0;
                                }
                            }
                        }
                    }
                }
            }
            else if (c == 3)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            if (arr[i][j][k])
                            {
                                if (!((i == ten && j == one && k == hund) ||
                                      (i == one && j == hund && k == ten)))
                                {
                                    arr[i][j][k] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (b == 1)
        {
            if (c == 0)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            if (arr[i][j][k])
                            {
                                if (!(((i == hund) && (j != hund && j != ten && j != one) && (k != hund && k != ten && k != one)) ||
                                      ((j == ten) && (i != hund && i != ten && i != one) && (k != hund && k != ten && k != one)) ||
                                      ((k == one) && (i != hund && i != ten && i != one) && (j != hund && j != ten && j != one))))
                                {
                                    arr[i][j][k] = 0;
                                }
                            }
                        }
                    }
                }
            }
            else if (c == 1)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            if (arr[i][j][k])
                            {
                                if (!(((i == hund) && (j == one) && (k != hund && k != ten && k != one)) ||
                                      ((i == hund) && (k == ten) && (j != hund && j != ten && j != one)) ||
                                      ((j == ten) && (i == one) && (k != hund && k != ten && k != one)) ||
                                      ((j == ten) && (k == hund) && (i != hund && i != ten && i != one)) ||
                                      ((k == one) && (j == hund) && (i != hund && i != ten && i != one)) ||
                                      ((k == one) && (i == ten) && (j != hund && j != ten && j != one))))
                                {
                                    arr[i][j][k] = 0;
                                }
                            }
                        }
                    }
                }
            }
            else if (c == 2)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            if (arr[i][j][k])
                            {
                                if (!(((i == hund) && (j == one) && (k == ten)) ||
                                      ((i == one) && (j == ten) && (k == hund)) ||
                                      ((i == ten) && (j == hund) && (k == one))))
                                {
                                    arr[i][j][k] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (b == 2)
        {
            if (c == 0)
            {
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            if (arr[i][j][k])
                            {
                                if (!((i == hund && j == ten && (k != hund && k != ten && k != one)) ||
                                      (i == hund && k == one && (j != hund && j != ten && j != one)) ||
                                      (j == ten && k == one && (i != hund && i != ten && i != one))))
                                {
                                    arr[i][j][k] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(b == 3){
            if(c == 0){
                for(int i=0;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int k=0;k<10;k++){
                            if(arr[i][j][k]){
                                if(!((i == hund && j == ten && k == one))){
                                    arr[i][j][k] = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (arr[i][j][k])
                {
                   cnt++;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}