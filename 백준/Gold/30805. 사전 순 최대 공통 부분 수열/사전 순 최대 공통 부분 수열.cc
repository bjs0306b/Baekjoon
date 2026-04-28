// #include <bits/stdc++.h>
// using namespace std;

// int dp[100][100];
// vector<int> saved[100][100];

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     int m;
//     cin >> m;
//     int arr2[m];
//     for (int i = 0; i < m; i++)
//         cin >> arr2[i];

//     vector<vector<int>> vec;

//     for (int i = 0; i < n; i++)
//     {
//         vector<int> temp;
//         for (int j = 0; j < m; j++)
//         {
//             if (arr[i] == arr2[j])
//                 temp.push_back(j);
//         }
//         if (temp.size())
//             vec.push_back(temp);
//     }

//     for (int i = 0; i < vec[0].size(); i++)
//     {
//         dp[0][vec[0][i]] = 1;
//         saved[0][vec[0][i]].push_back(vec[0][i]);
//     }

//     // for (int i = 0; i < vec.size(); i++)
//     // {
//     //     for(int j=0; j<vec[i].size();j++){
//     //         cout << vec[i][j] << " ";
//     //     }
//     //     cout << '\n';
//     // }

//     int maxmax = 0;
//     int ans_x, ans_y;
//     for (int i = 1; i < vec.size(); i++)
//     {
//         for (int j = 0; j < vec[i].size(); j++)
//         {
//             int mx = 0;
//             int mx_x, mx_y;
//             for (int k = 0; k < i; k++)
//             {
//                 for (int s = 0; s < vec[i][j]; s++)
//                 {
//                     if (dp[k][s] > mx)
//                     {
//                         mx = dp[k][s];
//                         mx_x = k;
//                         mx_y = s;
//                     }
//                 }
//             }
//             if (maxmax <= mx)
//             {
//                 ans_x = i;
//                 ans_y = vec[i][j];
//                 maxmax = mx + 1;
//             }
//             dp[i][vec[i][j]] = mx + 1;
//             saved[i][vec[i][j]] = saved[mx_x][mx_y];
//             saved[i][vec[i][j]].push_back(vec[i][j]);
//         }
//     }

//     // for(int i=0;i<saved[ans_x][ans_y].size();i++) cout << saved[ans_x][ans_y][i] << " ";
//     // cout << "\n";
//     // cout << maxmax << " " << ans_x << " " << ans_y;

//     vector<int> ans_vec;
//     for (int i = 0; i < saved[ans_x][ans_y].size(); i++)
//         ans_vec.push_back(arr2[saved[ans_x][ans_y][i]]);
//     auto iter = ans_vec.begin();

//     vector<int> ans;
//     for (;;)
//     {
//         auto temp = max_element(iter + 1, ans_vec.end());
//         ans.push_back(*temp);
//         iter = temp;

//         if (iter == --ans_vec.end())
//             break;
//     }

//     cout << ans.size() << "\n";
//     for (int i = 0; i < ans.size(); i++)
//         cout << ans[i] << " ";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    deque<int> vec1(n);
    for (int i = 0; i < n; i++)
        cin >> vec1[i];
    cin >> n;
    deque<int> vec2(n);
    for (int i = 0; i < n; i++)
        cin >> vec2[i];

    vector<int> ans;

    for(;;){
        if(vec1.empty() || vec2.empty()) break;
        auto temp1 = max_element(vec1.begin(), vec1.end()), temp2 = max_element(vec2.begin(), vec2.end());
        if (*temp1 == *temp2)
        {
            ans.push_back(*temp1);
            for (;;)
            {
                if (vec1.front() == *temp1)
                {
                    vec1.pop_front();
                    break;
                }
                vec1.pop_front();
            }
            for (;;)
            {
                if (vec2.front() == *temp2)
                {
                    vec2.pop_front();
                    break;
                }
                vec2.pop_front();
            }
        }
        else if (*temp1 > *temp2)
            vec1.erase(temp1);
        else
            vec2.erase(temp2);
    }

    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";

    return 0;
}