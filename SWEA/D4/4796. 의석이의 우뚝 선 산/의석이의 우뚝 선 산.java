
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, ans;
	static int[] A;
	
	static void input() throws IOException {
		ans = 0;
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		n = Integer.parseInt(st.nextToken());
		A = new int[n];	
		for (int i = 0; i < n; i++) {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
			A[i] = Integer.parseInt(st.nextToken());
		}
	}
	
	static void solve() {
		boolean flag = false; // true : 내려가는 상태, false : x`올라가는 상태
		int up = 0, down = 0;
		for(int i=0;i<n-1;i++) {
			if(A[i] < A[i+1]) {
				if(flag) {
					ans += up * down;
					up = 1;
					down = 0;
					flag = false;
				}
				else {
					up++;
				}
			}
			else {
				if(flag) {
					down++;
				}
				else {
					flag = true;
					down++;
				}
			}
		}
		ans += up * down;
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int i=1;i<=t;i++) {
			System.out.print("#" + i + " ");
			input();
			solve();
			System.out.println(ans);
		}
	}
}
