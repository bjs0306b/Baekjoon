

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, ans;
	static int visited[][];
	
	static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		ans = 0;
		visited = new int[n][n];
	}
	
	static boolean isIn(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < n;
	}
	
	static void visit(int x, int y) {
		int temp = 1;
		for(;;) {
			if(!isIn(x+temp, y)) break;
			visited[x+temp][y]++;
			temp++;
		}
		temp = 1;
		for(;;) {
			if(!isIn(x+temp, y+temp)) break;
			visited[x+temp][y+temp]++;
			temp++;
		}
		temp = 1;
		for(;;) {
			if(!isIn(x+temp, y-temp)) break;
			visited[x+temp][y-temp]++;
			temp++;
		}
	}
	
	static void unvisit(int x, int y) {
		int temp = 1;
		for(;;) {
			if(!isIn(x+temp, y)) break;
			visited[x+temp][y]--;
			temp++;
		}
		temp = 1;
		for(;;) {
			if(!isIn(x+temp, y+temp)) break;
			visited[x+temp][y+temp]--;
			temp++;
		}
		temp = 1;
		for(;;) {
			if(!isIn(x+temp, y-temp)) break;
			visited[x+temp][y-temp]--;
			temp++;
		}
	}
	
	static void dfs(int x, int y) {
		if(x == n-1) {
			ans++;
			return;
		}
		for(int i=0;i<n;i++) {
			if(visited[x+1][i] == 0) {
				visit(x+1, i);
				dfs(x+1, i);
				unvisit(x+1, i);
			}
		}
	}
	
	static void solve() {
		for(int i=0;i<n;i++) {
			visit(0,i);
			dfs(0,i);
			unvisit(0,i);
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
