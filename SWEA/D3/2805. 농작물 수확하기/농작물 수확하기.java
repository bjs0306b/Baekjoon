
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n;
	static int[][] A;
	
	static void input() throws IOException {
		String s = br.readLine();
		n = Integer.parseInt(s);
		A = new int[n][n];	
		for(int i=0;i<n;i++) {
			s = br.readLine();
			for(int j=0;j<n;j++) A[i][j] = (s.charAt(j) - '0');
		}
	}
	
	static int solve() {
		int ret = 0;
		
		for(int i=0;i<n;i++) {
			int mn = Math.min(i, n-1-i);
			for(int j=n/2-mn;j<=n/2+mn;j++) {
				// System.out.println(i + " " + j + " " + A[i][j]);
				ret += A[i][j];
			}
		}
		
		return ret;
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int i=1;i<=t;i++) {
			System.out.print("#" + i + " ");
			input();
			System.out.println(solve());
		}
	}
}
