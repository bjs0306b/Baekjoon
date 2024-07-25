#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    
    for(int i=0;i<n;i++){
        string s; cin >> s;
        int num; cin >> num; 
        
        deque<int> v;
        string arr_str; cin >> arr_str;
        
        string temp = "";
        for(int j=0;j<arr_str.size();j++){
            if(arr_str[j] >= '0' && arr_str[j] <= '9'){
                temp += arr_str[j];
            }
            else{
                if(temp != "") v.push_back(stoi(temp));
                temp="";
            }
        }
        
        bool left = true;
        bool flag = true;
        for(int j=0;j<s.size();j++){
            if(s[j] == 'R'){
                if(left) left = false;
                else left = true;
            }
            else if(s[j] == 'D'){
                if(v.size()){
                    if(left) v.pop_front();
                    else v.pop_back();
                }
                else {cout << "error\n"; flag=false; break;}
            }
        }
        if(!left) reverse(v.begin(), v.end());

        if(flag){
            cout << "[";
            for (int j = 0; j < v.size(); j++) {
                cout << v[j];
                if (j < v.size() - 1) cout << ",";
            }
            cout << "]\n";
        }
    }
    
    return 0;
}