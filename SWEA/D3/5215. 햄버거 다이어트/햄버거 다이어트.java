

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, l;
	static int[][] v;
	static int ans;
	
	static void input() throws IOException {
		ans = 0;
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());
		
		v = new int[n][2];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<2;j++) {	
				v[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	static void dfs(int dep, int s, int taste, int cal) {
		if(dep == 0){
			ans = Math.max(ans, taste);
			return;
		}
		for(int i=s;i<n;i++) {
			if(cal + v[i][1] <= l ) dfs(dep-1, i+1, taste+v[i][0], cal + v[i][1]);
		}
	}
	
	static void solve() {
		for(int i=1;i<=n;i++) dfs(i, 0, 0, 0);
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
