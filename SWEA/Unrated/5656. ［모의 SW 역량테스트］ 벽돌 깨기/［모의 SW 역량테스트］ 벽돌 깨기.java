import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int k,n,m;
	static int ans;
	static int dx[] = {-1,1,0,0}, dy[] = {0,0,1,-1};
	
	static void bomb(int[][] A, int x, int y) {
		int size = A[x][y];
		A[x][y] = 0;
		for(int i=1;i<size;i++) {
			for(int j=0;j<4;j++) {
				int nx = x + dx[j]*i, ny = y + dy[j]*i;
				if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if(A[nx][ny] > 0) bomb(A, nx, ny);
				}
			}
		}
		
	}
	
	static void down(int[][] A) {
		for(int i=0;i<m;i++) {
			ArrayList<Integer> temp = new ArrayList<>();
			for(int j=n-1;j>=0;j--) {
				if(A[j][i] > 0) temp.add(A[j][i]);
			}
			
			for(int j=0;j<temp.size();j++) {
				A[n-1-j][i] = temp.get(j);
			}
			for(int j=temp.size();j<n;j++) {
				A[n-1-j][i] = 0;
			}
		}
	}
	
	static void dfs(int dep, int[][] A) {
		if(dep == k) {
			int cnt = 0;
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(A[i][j] > 0) cnt++;
				}
			}
			ans = Math.min(ans, cnt);
			
			return;
		}
		
		
		for(int i=0;i<m;i++) {
			
			int[][] temp = new int[n][m];
			for(int j=0;j<n;j++) {
				for(int k=0;k<m;k++) {
					temp[j][k] = A[j][k];
				}
			}
			
			boolean flag = false;
			for(int j=0;j<n;j++) {
				if(temp[j][i] > 0) {
					bomb(temp, j, i);
					down(temp);
					flag = true;
					break;
				}
			}
			if(flag) dfs(dep+1, temp);
		}
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		
		for(int T=1;T<=t;T++) {
			System.out.print("#" + T + " ");
			st = new StringTokenizer(br.readLine());
			k = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			
			ans = Integer.MAX_VALUE;
			
			int[][] A = new int[n][m];
			for(int i=0;i<n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<m;j++) {
					A[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			dfs(0, A);
			if(ans == Integer.MAX_VALUE) ans = 0; // k번까지 가기 전에 다 터짐.
			System.out.println(ans);
		}
	}
}
