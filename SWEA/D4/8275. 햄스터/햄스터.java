
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n,x,m;
	static int[] v;
	static int[][] a;
	static int total_sum_max;
	static int[] ans;
	
	static void dfs(int dep) {
		
		if(dep == n) {
			boolean flag = true;
			for(int i=0;i<m;i++) {
				int s = a[i][0]-1, e = a[i][1]-1;
				int sum = 0;
				for(int j=s;j<=e;j++) sum += v[j];
				if(sum != a[i][2]) {
					flag = false;
					break;
				}
			}
			if(flag) {
				int sum = 0;
				for(int i=0;i<n;i++) sum += v[i];
				if(sum > total_sum_max) {
					total_sum_max = sum;
					for(int i=0;i<n;i++) ans[i] = v[i];
				}
			}
			return;
		}
		
		for(int i=0;i<=x;i++) {
			v[dep] = i;
			dfs(dep+1);
		}
	}
	
	static void solve() throws IOException {	
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		total_sum_max = -1;
		a = new int[m][3];
		v = new int[n];
		ans = new int[n];
		for(int i=0;i<m;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<3;j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		dfs(0);
		
		if(total_sum_max == -1) System.out.println(-1);
		else {
			for(int i=0;i<n;i++) System.out.print(ans[i] + " ");
			System.out.println();
		}
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int i=1;i<=t;i++) {
			System.out.print("#" + i + " ");
			solve();
		}
	}
}
