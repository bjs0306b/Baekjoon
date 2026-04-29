import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int T=1;T<=t;T++) {
			
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			
			int A[][] = new int[n][n];
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<n;j++) {
					A[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			int ans = 0;
			// 가로
			for(int i=0;i<n;i++) {
				boolean flag = true;
				for(int j=1;j<n;j++) if(Math.abs(A[i][j] - A[i][j-1]) > 1) {
					flag = false;
					break;
				}
				if(!flag) continue;
				boolean installed[] = new boolean[n];
				
				int cur = A[i][0];
				int cnt = 1;
				for(int j=1;j<n;j++) {
					if(A[i][j] == cur) {
						cnt++;
					}
					else if(A[i][j] > cur){
						if(cnt >= m) {
							for(int k=j-m;k<j;k++) {
								if(installed[k]) {
									flag = false;
									break;
								}
								installed[k] = true;
							}
							if(!flag) break;
						}
						else {
							flag = false;
							break;
						}
						cur = A[i][j];
						cnt = 1;
					}
					else {
						cur = A[i][j];
						cnt = 1;
					}
				}
				if(!flag) continue;
				
				cur = A[i][n-1];
				cnt = 1;
				for(int j=n-2;j>=0;j--) {
					if(A[i][j] == cur) {
						cnt++;
					}
					else if(A[i][j] > cur){
						if(cnt >= m) {
							for(int k=j+1;k<=j+m;k++) {
								if(installed[k]) {
									flag = false;
									break;
								}
								installed[k] = true;
							}
							if(!flag) break;
						}
						else {
							flag = false;
							break;
						}
						cur = A[i][j];
						cnt = 1;
					}
					else {
						cur = A[i][j];
						cnt = 1;
					}
				}
				if(flag) {
					//System.out.println(i);
					ans++;
				}
			}
			
			// 세로
			for(int i=0;i<n;i++) {
				boolean installed[] = new boolean[n];
				boolean flag = true;
				for(int j=1;j<n;j++) if(Math.abs(A[j][i] - A[j-1][i]) > 1) {
					flag = false;
					break;
				}
				if(!flag) continue;
				int cur = A[0][i];
				int cnt = 1;
				for(int j=1;j<n;j++) {
					if(A[j][i] == cur) {
						cnt++;
					}
					else if(A[j][i] > cur){
						if(cnt >= m) {
							for(int k=j-m;k<j;k++) {
								if(installed[k]) {
									flag = false;
									break;
								}
								installed[k] = true;
							}
							if(!flag) break;
						}
						else {
							flag = false;
							break;
						}
						cur = A[j][i];
						cnt = 1;
					}
					else {
						cur = A[j][i];
						cnt = 1;
					}
				}
				if(!flag) continue;
				
				cur = A[n-1][i];
				cnt = 1;
				for(int j=n-2;j>=0;j--) {
					if(A[j][i] == cur) {
						cnt++;
					}
					else if(A[j][i] > cur){
						if(cnt >= m) {
							for(int k=j+1;k<=j+m;k++) {
								if(installed[k]) {
									flag = false;
									break;
								}
								installed[k] = true;
							}
							if(!flag) break;
						}
						else {
							flag = false;
							break;
						}
						cur = A[j][i];
						cnt = 1;
					}
					else {
						cur = A[j][i];
						cnt = 1;
					}
				}
				if(flag) {
					//System.out.println(i);
					ans++;
				}
			}
			
			System.out.println("#" + T + " " + ans);
		}
	}
}
