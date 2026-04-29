

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n,m,c, ans;
	static int mx[];
	static int[][] A;
	static void input() throws IOException {
		ans = 0;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		
		A = new int[n][n];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<n;j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	static boolean visited[];
	static void dfs(int x, int y, int dep, int idx) {
		if(dep == m) {
			int sum = 0, square_sum = 0;
			for(int i=0;i<m;i++) if(visited[i]) {sum += A[x][y+i]; square_sum += A[x][y+i]*A[x][y+i];}
			if(sum > c) return;
			mx[idx] = Math.max(mx[idx], square_sum);
			return;
		}
		dfs(x, y, dep+1, idx);
		visited[dep] = true;
		dfs(x, y, dep+1, idx);
		visited[dep] = false;
	}
	
	static void collect_honey(int x1, int y1, int x2, int y2) {
		mx = new int[2];
		visited = new boolean[m];
		
		dfs(x1, y1, 0, 0);
		dfs(x2, y2, 0, 1);
		
		ans = Math.max(ans, mx[0]+mx[1]);
	}
	
	static void solve() {
		
		
		for(int i=0;i<n;i++) {
			for(int j=0;j<=n-m;j++) {
				for(int k=0;k<n;k++) {
					for(int l=0;l<=n-m;l++) {
						if(i == k && (j+m-1 >= l || l+m-1 >= j)) continue; // 행이 같은데 열이 겹침.
						collect_honey(i, j, k, l);
					}
				}
			}
		}
		
		System.out.println(ans);
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int i=1;i<=t;i++) {
			System.out.print("#" + i + " ");
			input();
			solve();
		}
	}
}
