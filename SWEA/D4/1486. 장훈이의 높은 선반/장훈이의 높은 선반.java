
import java.util.Scanner;

public class Solution {
	
	static Scanner sc = new Scanner(System.in);
	static int n,b, ans;
	static int[] A;
	static void input() {
		ans = Integer.MAX_VALUE;
		n = sc.nextInt();
		b = sc.nextInt();
		A = new int[n];
		for(int i=0;i<n;i++) A[i] = sc.nextInt();
	}
	
	static void dfs(int dep, int sum) {
		if(dep == n) {
			if(sum >= b) {
				ans = Math.min(ans, sum);
			}
			return;
		}
		dfs(dep+1, sum);
		dfs(dep+1, sum+A[dep]);
	}
	
	static void solve() {
		dfs(0, 0);
		System.out.println(ans - b);
	}
	
	public static void main(String[] args) {
		int t = sc.nextInt();
		for(int i=1;i<=t;i++) {
			System.out.print("#" + i + " ");
			input();
			solve();
		}
	}

}
