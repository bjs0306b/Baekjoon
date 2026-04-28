#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    double total_score = 0;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        double s,a,t,m;
        cin >> s >> a >> t >> m;
        double score = s*(1+1/a)*(1+m/t)/4;
        total_score += score;
    }
    // cout << total_score;

    int ranking = 1;
    int m; cin >> m;
    for(int i=0;i<m;i++){
        double d; cin >> d;
        if(total_score < d) ranking++;
    }
    cout << "The total score of Younghoon";
    if(100*ranking <= 15*(m+1)) cout << " \"The God\"";
    cout << " is ";
    cout << fixed << setprecision(2) << total_score;
    cout << ".";
    
    
    return 0;
}