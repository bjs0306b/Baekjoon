#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int arr[21];
    for (int i = 1; i < 21; i++)
        arr[i] = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "add")
        {
            int num;
            cin >> num;
            arr[num] = 1;
        }
        else if (str == "check")
        {
            int num;
            cin >> num;
            if (arr[num] == 1)
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (str == "remove")
        {
            int num;
            cin >> num;
            arr[num] = 0;
        }
        else if (str == "toggle")
        {
            int num;
            cin >> num;
            if (arr[num] == 1)
                arr[num] = 0;
            else
                arr[num] = 1;
        }
        else if (str == "all")
            for (int i = 1; i < 21; i++)
                arr[i] = 1;
        else if (str == "empty")
            for (int i = 1; i < 21; i++)
                arr[i] = 0;
    }

    return 0;
}

// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);
//     int n;
//     cin >> n;
//     set<int> s;
//     for(int i=0;i<n;i++){
//         string str; cin >> str;
//         if(str == "add"){
//             int num; cin >> num;
//             s.insert(num);
//         }
//         else if(str == "check"){
//             int num; cin >> num;
//             if(binary_search(s.begin(), s.end(), num)) cout << "1"<<"\n";
//             else cout << "0" <<"\n";
//         }
//         else if(str == "remove"){
//             int num; cin >> num;
//             s.erase(num);
//         }
//         else if(str == "toggle"){
//             int num; cin >> num;
//             if(binary_search(s.begin(), s.end(), num)) s.erase(num);
//             else s.insert(num);
//         }
//         else if(str == "all"){
//             s.clear();
//             for(int i=1;i<21;i++) s.insert(i);
//         }
//         else if(str == "empty") s.clear();
//     }

//     return 0;
// }