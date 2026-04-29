
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static  StringTokenizer st;
	static int n, m, cnt;
	static boolean cant[][];
	static boolean visited[];
	
	static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		cant = new boolean[n][n];
		visited = new boolean[n];
		cnt = 0;
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--;
			b--;
			cant[a][b] = true;
			cant[b][a] = true;
		}
	}
	
	static void dfs(int dep) {
		if(dep == n) {
			cnt++;
			return;
		}
		
		dfs(dep+1);
		
		boolean flag = true;
		// 방문 했는데 나쁜 조합이면 x
		for(int i=0;i<dep;i++) if(visited[i] && cant[i][dep]) {flag = false; break;}
		if(flag) {
			visited[dep] = true;
			dfs(dep+1);
			visited[dep] = false;
		}
				
		
	}
	
	static void solve() {
		dfs(0);
		System.out.println(cnt);
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
