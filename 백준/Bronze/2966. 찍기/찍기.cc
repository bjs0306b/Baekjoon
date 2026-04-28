#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int Adrian=0, Bruno=0, Goran=0;
    vector<char> v;
    for(int i=0;i<n;i++){
        char c; cin >> c;
        v.push_back(c);
    }

    for(int i=0;i<n;i++){

        if(i%3==0){
            if(v[i]=='A') Adrian++;
        }
        else if(i%3==1){
            if(v[i]=='B') Adrian++;
        }
        else{
            if(v[i]=='C') Adrian++;
        }


        if(i%4==0){
            if(v[i]=='B') Bruno++;
        }
        else if(i%4==1){
            if(v[i]=='A') Bruno++;
        }
        else if(i%4==2){
            if(v[i]=='B') Bruno++;
        }
        else{
            if(v[i]=='C') Bruno++;
        }


        if(i%6==0){
            if(v[i]=='C') Goran++;
        }
        else if(i%6==1){
            if(v[i]=='C') Goran++;
        }
        else if(i%6==2){
            if(v[i]=='A') Goran++;
        }
        else if(i%6==3){
            if(v[i]=='A') Goran++;
        }
        else if(i%6==4){
            if(v[i]=='B') Goran++;
        }
        else{
            if(v[i]=='B') Goran++;
        }
    }

    int max_score = max(Adrian, max(Bruno, Goran));
    cout << max_score << "\n";
    if(Adrian==max_score) cout << "Adrian\n";
    if(Bruno==max_score) cout << "Bruno\n";
    if(Goran==max_score) cout << "Goran\n";
    
    return 0;
}