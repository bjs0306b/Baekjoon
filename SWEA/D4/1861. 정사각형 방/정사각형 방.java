
import java.util.Scanner;

public class Solution {
	static Scanner sc = new Scanner(System.in);
	static int n, cnt;
	static int[][] A;
	
	static void input(){
		n = sc.nextInt();
		A = new int[n][n];
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) A[i][j] = sc.nextInt();
	}
	
	static int[] dx = new int[] {-1,1,0,0}, dy = new int[] {0,0,-1,1};
	static void dfs(int dep, int x, int y) {
		cnt = Math.max(cnt, dep);
		for(int i=0;i<4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if(A[x][y] + 1 == A[nx][ny]) dfs(dep+1, nx, ny);
			}
		}
	}
	
	static int[] solve() {
		int[] ret = new int[2];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cnt = 0;
				dfs(1,i,j);
				if(ret[1] < cnt) {
					ret[1] = cnt;
					ret[0] = A[i][j];
				}
				else if(ret[1] == cnt) {
					ret[0] = Math.min(ret[0], A[i][j]);
				}
			}
		}
		return ret;
	}
	
	public static void main(String[] args) {
		
		int t = sc.nextInt();
		for(int i=1;i<=t;i++) {
			input();
			int[] temp = solve();
			System.out.println("#" + i + " " + temp[0] + " " + temp[1]);
		}
	}

}
