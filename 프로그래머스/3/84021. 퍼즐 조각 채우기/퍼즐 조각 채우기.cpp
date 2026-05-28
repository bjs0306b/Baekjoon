#include <string>
#include <vector>
#include <memory.h>
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> cnt;
long long n;
bool visited[50][50];
long long dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
long long two_pow[36];


long long solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    n = game_board.size();
    cnt.clear();
    two_pow[0] = 1;
    long long ans = 0;
    for(long long i=1;i<36;i++){
        two_pow[i] = 2 * two_pow[i-1];
    }
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) visited[i][j] = false;
                                                                                                    
    memset(visited, false, sizeof(visited));
    queue<pair<long long,long long>> q;
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            if(visited[i][j]) continue;
            if(game_board[i][j]) continue;
            long long sum = 0;
            q.push({i, j});
            visited[i][j] = true;
            
            long long mn_x = i, mn_y = j;
            vector<pair<long long,long long>> temp;
            while(!q.empty()){
                auto f = q.front(); q.pop();
                mn_x = min(mn_x, f.first);
                mn_y = min(mn_y, f.second);
                temp.push_back(f);
                for(long long k=0;k<4;k++){
                    long long nx = f.first + dx[k], ny = f.second + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && game_board[nx][ny] == 0){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            
            for(auto k : temp){
                long long x = k.first - mn_x, y = k.second - mn_y;
                long long num = x * 6 + y;
                sum += two_pow[num];
            }
            cout << sum << "\n";
            cnt[sum]++;
        }
    }
    cout << "\n";
    
    for(long long i=0;i<n;i++) for(long long j=0;j<n;j++) visited[i][j] = false;
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            if(visited[i][j]) continue;
            if(table[i][j] == 0) continue;
            long long sum = 0;
            q.push({i, j});
            visited[i][j] = true;
            
            long long mn_x = i, mn_y = j;
            vector<pair<long long,long long>> temp;
            while(!q.empty()){
                auto f = q.front(); q.pop();
                mn_x = min(mn_x, f.first);
                mn_y = min(mn_y, f.second);
                temp.push_back(f);
                for(long long k=0;k<4;k++){
                    long long nx = f.first + dx[k], ny = f.second + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && table[nx][ny] == 1){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            
            //cout << "\n";
            for(int k=0;k<temp.size();k++){
                temp[k].first -= mn_x;
                temp[k].second -= mn_y;
                long long num = temp[k].first * 6 + temp[k].second;
                sum += two_pow[num];
            }
 
            cout << sum << "\n";
            
            if(cnt[sum]){
                ans += temp.size();
                cnt[sum]--;
                cout << "\n";
                continue;
            }
            
            for(long long i=0;i<3;i++){
                sum = 0;
                mn_x = 6, mn_y = 6;
                for(long long j=0;j<temp.size();j++){
                    long long nx = temp[j].second, ny = 5 - temp[j].first;
                    mn_x = min(mn_x, nx);
                    mn_y = min(mn_y, ny);
                    temp[j] = {nx, ny};
                }
                for(long long j=0;j<temp.size();j++){
                    long long x = temp[j].first - mn_x, y = temp[j].second - mn_y;
                    long long num = 6 * x + y;
                    sum += two_pow[num];
                }
                cout << sum << "\n";
                if(cnt[sum]){
                    ans += temp.size();
                    cnt[sum]--;
                    break;
                }
            }
            cout << "\n";
        }
    }
    
    return ans;
}