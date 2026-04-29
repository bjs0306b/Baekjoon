
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		for(int t=1;t<=T;t++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#" + t + " ");
			
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
			st = new StringTokenizer(br.readLine());
			int[] A = new int[n];
			for(int i=0;i<n;i++) {
				A[i] = Integer.parseInt(st.nextToken());
			}
			
			Arrays.sort(A);
			
			int s = 0, e = n-1, ans = -1;
			while(s < e) {
				int sum = A[s] + A[e];
				if(sum == m) {
					ans = sum;
					break;
				}
				else if(sum < m) {
					ans = Math.max(ans, sum);
					s++;
				}
				else e--;
			}
			
			sb.append(ans);
			System.out.println(sb.toString());
		}
	}
}