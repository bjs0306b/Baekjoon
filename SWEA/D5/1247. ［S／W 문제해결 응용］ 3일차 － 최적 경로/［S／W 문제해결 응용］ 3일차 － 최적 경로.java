import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[][] dp;
	static int[][] dis; 
	static int n;
	
	static int tsp(int cur, int visited) {
		if(visited == (1 << (n+1)) - 1) {
			return dis[cur][n+1];
		}
		if(dp[cur][visited] != -1) return dp[cur][visited];
		
		int ret = 1000000000;
		for(int i=1;i<n+1;i++) {
			if((visited & (1 << i)) != 0) continue; // 이미 방문
			ret = Math.min(ret, tsp(i, visited | (1<<i)) + dis[cur][i]);
		}
		return dp[cur][visited] = ret;
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		
		for(int T=1;T<=t;T++) {
			System.out.print("#" + T + " ");
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			int[][] coor = new int[n+2][2];
			dis = new int[n+2][n+2];
			dp = new int[n+1][1<<(n+1)];
			for(int i=0;i<n+1;i++) {
				for(int j=0;j<(1<<(n+1));j++) {
					dp[i][j] = -1;
				}
			}
			
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<2;j++) {
				coor[0][j] = Integer.parseInt(st.nextToken());
			}
			for(int j=0;j<2;j++) {
				coor[n+1][j] = Integer.parseInt(st.nextToken());
			}
			for(int i=1;i<n+1;i++) {
				for(int j=0;j<2;j++) {
					coor[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			for(int i=0;i<n+2;i++) {
				for(int j=0;j<n+2;j++) {
					dis[i][j] = Math.abs(coor[i][0] - coor[j][0]) + Math.abs(coor[i][1] - coor[j][1]);
				}
			}
			System.out.println(tsp(0, 1));
		}
	}
}
