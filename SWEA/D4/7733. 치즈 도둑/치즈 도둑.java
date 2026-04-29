import java.util.Scanner;

public class Solution {
	
	static Scanner sc = new Scanner(System.in);
	static int n;
	static int[][] A;
	static boolean[][] visited;
	static int[] dx = {-1,1,0,0}, dy = {0,0,-1,1};
	
	static void dfs(int x, int y, int num) {
		for(int i=0;i<4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && A[nx][ny] > num) {
				visited[nx][ny] = true;
				dfs(nx, ny, num);
			}
		}
	}
	
	static int cnt_loaf(int num) {
		visited = new boolean[n][n];
		int cnt = 0;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(A[i][j] > num && !visited[i][j]) {
					dfs(i,j, num);
					cnt++;
				}
			}
		}
		return cnt;
	}
	
	public static void main(String[] args) {
		int t = sc.nextInt();
		for(int i=1;i<=t;i++) {
			n = sc.nextInt();
			A = new int[n][n];
			int mx = 0;
			int ans = 0;
			for(int j=0;j<n;j++) for(int k=0;k<n;k++) {A[j][k] = sc.nextInt(); mx = Math.max(mx,  A[j][k]);}
			for(int j=0;j<=mx;j++) {
				int temp = cnt_loaf(j);
				ans = Math.max(ans, temp);
			}
			System.out.println("#" + i + " " + ans);
		}
	}

}
