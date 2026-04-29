

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n;
	static int[] A, oper;
	static int mx,mn;
	
	static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		oper = new int[4];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<4;i++) {
			oper[i] = Integer.parseInt(st.nextToken());
		}
		A = new int[n];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<n;i++) {
			A[i] = Integer.parseInt(st.nextToken());
		}
		// System.out.println(Arrays.toString(A));
		
		mx = Integer.MIN_VALUE;
		mn = Integer.MAX_VALUE;
	}
	
	static void dfs(int dep, int ans) {
		if(dep == n-1) {
			//System.out.println(ans);
			mx = Math.max(mx, ans);
			mn = Math.min(mn, ans);
			return;
		}
		for(int i=0;i<4;i++) {
			if(oper[i] == 0) continue;
			oper[i]--;
			//System.out.println(dep + " " + i + " " + ans);
			
			if(i == 0) {
				dfs(dep+1, ans+A[dep+1]);
			}
			else if(i == 1) {
				dfs(dep+1, ans-A[dep+1]);
			}
			else if(i == 2) {
				dfs(dep+1, ans*A[dep+1]);
			}
			else if(i == 3) {
				dfs(dep+1, ans/A[dep+1]);
			}
			
			oper[i]++;
		}
	}
	
	static void solve() {
		dfs(0, A[0]);
		System.out.println(mx - mn);
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
