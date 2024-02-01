#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int pluss(char a, char b){
    int m,n; 
    m = a - '0'; n = b - '0';
    return m+n;
}
int minuss(char a, char b){
    int m,n; 
    m = a - '0'; n = b - '0';
    return m-n;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b; cin>>a>>b;
    int signa,signb, swapp=0;
    if(a[0] == '-'){signa = 1; a = a.substr(1);} //substr 로 문자열 추출
    else signa = 0;
    if(b[0] == '-'){signb = 1; b = b.substr(1);}
    else signb = 0;
    if(signa+signb==1 && a==b){ cout << 0; return 0;}
    if((a.size() < b.size()) || (a.size() == b.size() && a<b)){swap(a,b);swapp = 1;}
    int minn = min(a.size(), b.size());
    auto itera = a.rbegin(), iterb = b.rbegin();
    vector<int> v;
    if(signa){ 
        if(signb){ // - -
            cout << "-";
            for(int i=0;i<minn;i++,itera++,iterb++) v.push_back(pluss(*itera, *iterb));
            while(itera != a.rend()) {v.push_back(pluss(*itera, '0')); itera++;}
            while(iterb != b.rend()) {v.push_back(pluss(*iterb, '0')); iterb++;}
            for(int i=0;i<v.size()-1;i++){
                if(v[i] > 9){ v[i]-=10; v[i+1]++;}
            }
            while(!v.empty()){
                cout << v.back();
                v.pop_back();
            }
        }
        else{ // - +
            if(!swapp) cout << "-";
            for(int i=0;i<minn;i++,itera++,iterb++) v.push_back(minuss(*itera, *iterb));
            while(itera != a.rend()) {v.push_back(minuss(*itera, '0')); itera++;}
            while(iterb != b.rend()) {v.push_back(minuss(*iterb, '0')); iterb++;}
           for(int i=0;i<v.size()-1;i++){
                if(v[i] < 0){ v[i]+=10; v[i+1]--;}
            }
            while(v.back()==0) v.pop_back();
            if(v.size()==0) cout << "0";
            else{
                while(!v.empty()){
                    cout << v.back();
                    v.pop_back();
                }
            }
        }
    }
    else{
        if(signb){ // + -
            if(swapp) cout << "-";
            for(int i=0;i<minn;i++,itera++,iterb++) v.push_back(minuss(*itera, *iterb));
            while(itera != a.rend()) {v.push_back(minuss(*itera, '0')); itera++;}
            while(iterb != b.rend()) {v.push_back(minuss(*iterb, '0')); iterb++;}
           for(int i=0;i<v.size()-1;i++){
                if(v[i] < 0){ v[i]+=10; v[i+1]--;}
            }
            while(v.back()==0) v.pop_back();
            if(v.size()==0) cout << "0";
            else{
                while(!v.empty()){
                    cout << v.back();
                    v.pop_back();
                }
            }
        }
        else{  // + +
            for(int i=0;i<minn;i++,itera++,iterb++) v.push_back(pluss(*itera, *iterb));
            while(itera != a.rend()) {v.push_back(pluss(*itera, '0')); itera++;}
            while(iterb != b.rend()) {v.push_back(pluss(*iterb, '0')); iterb++;}
            for(int i=0;i<v.size()-1;i++){
                if(v[i] > 9){ v[i]-=10; v[i+1]++;}
            }
            while(!v.empty()){
                cout << v.back();
                v.pop_back();
            }
        }
    }
    
    return 0;
}