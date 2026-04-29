

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		for(int t=1;t<=T;t++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#" + t + " ");
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
			int[][] A = new int[n+1][n+1];
			
			for(int i=1;i<=n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=1;j<=n;j++) {
					A[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			int[][] pre_sum = new int[n+1][n+1];
			
			for(int i=1;i<=n;i++) {
				for(int j=1;j<=n;j++) {
					pre_sum[i][j] = pre_sum[i-1][j] + pre_sum[i][j-1] - pre_sum[i-1][j-1] + A[i][j];
				}
			}
			
			int mx = 0;
			for(int i=1;i<=n-m+1;i++) {
				for(int j=1;j<=n-m+1;j++) {
					int flies = pre_sum[i+m-1][j+m-1] - pre_sum[i-1][j+m-1] - pre_sum[i+m-1][j-1] + pre_sum[i-1][j-1];	
					mx = Math.max(mx, flies);
				}
			}
			sb.append(mx);
			System.out.println(sb.toString());
		}
	}
}