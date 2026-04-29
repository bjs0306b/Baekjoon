import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int[][] A;
	static int n;
	static boolean[][] visited;
	static int[] dx = {-1,-1,-1,0,1,1,1,0}, dy = {-1,0,1,1,1,0,-1,-1};
	
	static void zero_dfs(int x, int y) {
		for(int i=0;i<8;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(!(nx >= 0 && nx < n && ny >= 0 && ny < n)) continue;
			if(A[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
				zero_dfs(nx, ny);
			}
			visited[nx][ny] = true;	
		}
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		
		for(int T=1;T<=t;T++) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			A = new int[n][n];
			visited = new boolean[n][n];
			for(int i=0;i<n;i++) {
				String temp = br.readLine();
				for(int j=0;j<n;j++) {
					char c = temp.charAt(j);
					if(c == '*') A[i][j] = -1;
					else A[i][j] = 0;
				}
			}
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(A[i][j] == -1) {
						for(int k=0;k<8;k++) {
							int nx = i + dx[k], ny = j + dy[k];
							if(!(nx >= 0 && nx < n && ny >= 0 && ny < n)) continue;
							if(A[nx][ny] != -1) A[nx][ny]++;
						}
					}
				}
			}
			
			int ans = 0;
			
			// 0 먼저
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(A[i][j] == 0 && !visited[i][j]) {
						ans++;
						visited[i][j] = true;
						zero_dfs(i, j);
					}
				}	
			}
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(A[i][j] > 0 && !visited[i][j]) {
						ans++;
					}
				}	
			}
			
			System.out.println("#" + T + " " + ans);
		}
	}
}
