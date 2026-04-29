import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
	
	
	static int solve() throws IOException {
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		boolean visited[][] = new boolean[n][m];
		ArrayDeque<int[]> q =new ArrayDeque<>(), demon = new ArrayDeque<>();
		char A[][] = new char[n][m];
		for(int i=0;i<n;i++) {
			String s = br.readLine();
			for(int j=0;j<m;j++) {
				A[i][j] = s.charAt(j);
				if(A[i][j] == '*') {
					demon.add(new int[] {i,j});
				}
				if(A[i][j] == 'S') {
					visited[i][j] = true;
					q.add(new int[] {i,j});
					A[i][j] = '.';
				}
			}
		}
		int ret = 1;
		
		while(!q.isEmpty()) {
			int size = demon.size();
			for(int k=0;k<size;k++) {
				int[] f = demon.poll();
				for(int i=0;i<4;i++) {
					int nx = f[0] + dx[i], ny = f[1] + dy[i];
					if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] != '*' && A[nx][ny] != 'D' && A[nx][ny] != 'X') {
						demon.add(new int[] {nx,ny});
						A[nx][ny] = '*';
					}
					
				}	
			}
			
			size = q.size();
			for(int k=0;k<size;k++) {
				int[] f = q.poll();
				for(int i=0;i<4;i++) {
					int nx = f[0] + dx[i], ny = f[1] + dy[i];
					if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
						if(A[nx][ny] == '.') {
							visited[nx][ny] = true;
							q.add(new int[] {nx, ny});
						}
						if(A[nx][ny] == 'D') {
							return ret;
						}
					}
					
				}	
			}
			ret++;
			
			
		}
		return -1;
	}
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int T=1;T<=t;T++) {
			System.out.print("#" + T + " " );
			int ans = solve();
			if(ans == -1) System.out.println("GAME OVER");
			else System.out.println(ans);
		}
	}
}
