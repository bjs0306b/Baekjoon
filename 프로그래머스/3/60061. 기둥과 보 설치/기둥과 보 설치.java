import java.util.*;

class Solution {
    
    boolean A[][][];
    int m;
    
    boolean is_ok(){
        for(int i=0;i<m+1;i++){
            for(int j=0;j<m+1;j++){
                if(A[0][i][j]){
                    if(j == 0) continue; // 바닥 위
                    if(A[0][i][j-1]) continue; // 다른 기둥 위
                    if(i > 0 && A[1][i-1][j] || A[1][i][j]) continue; // 보 위에
                    return false;
                }
            }
        }
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<m+1;j++){
                if(A[1][i][j]){
                    if(A[0][i][j-1] || A[0][i+1][j-1]) continue; // 한쪽 끝 부분이 기둥 위
                    if(i > 0 && A[1][i-1][j] && i < m && A[1][i+1][j]) continue; // 양쪽 끝 부분이 다른 보와 동시에 연결
                    return false;
                }
            }
        }
        return true;
    }
    
    public int[][] solution(int n, int[][] build_frame) {
        m = n;
        A = new boolean[2][n+1][n+1];
        
        for(int i=0;i<build_frame.length;i++){
            int[] temp = build_frame[i];
            boolean flag = false;
            if(temp[3] == 1) flag = true;
            A[temp[2]][temp[0]][temp[1]] = flag;
            
            if(!is_ok()) A[temp[2]][temp[0]][temp[1]] = !flag;
        }
        
        int cnt = 0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                for(int k=0;k<2;k++){
                    if(A[k][i][j]){
                        cnt++;
                    }
                }
            }
        }
        int[][] answer = new int[cnt][3];
        int idx = 0;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                for(int k=0;k<2;k++){
                    if(A[k][i][j]){
                        answer[idx++] = new int[]{i,j,k};
                    }
                }
            }
        }
        return answer; 
    }
}