
import java.util.Scanner;

public class Solution {
	static Scanner sc = new Scanner(System.in);
	
	static int n, ans;
	static int[][] A;
	static boolean[] visited;
	
	static void dfs(int dep, int s) {
		if(dep == n/2) {
			int sum1 = 0, sum2 = 0;
			for(int i=0;i<n-1;i++) {
				if(visited[i]) continue;
				for(int j=i+1;j<n;j++) {
					if(visited[j]) continue;
					sum1 += (A[i][j] + A[j][i]);
				}
			}
			for(int i=0;i<n-1;i++) {
				if(!visited[i]) continue;
				for(int j=i+1;j<n;j++) {
					if(!visited[j]) continue;
					sum2 += (A[i][j] + A[j][i]);
				}
			}
			ans = Math.min(ans, Math.abs(sum1 - sum2));
			return;
		}
		for(int i=s;i<n;i++) {
			visited[i] = true;
			dfs(dep+1, i+1);
			visited[i] = false;
		}
	}
	
	public static void main(String[] args) {
		int t = sc.nextInt();
		for(int T=1;T<=t;T++) {
			n = sc.nextInt();
			A = new int[n][n];
			ans = Integer.MAX_VALUE;
			visited = new boolean[n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					A[i][j] = sc.nextInt();
				}
			}
			
			dfs(0, 0);
			
			System.out.println("#" + T + " " + ans);
		}
	}

}
