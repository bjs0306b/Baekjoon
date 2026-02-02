import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static int x1,y1,x2,y2;
	static int[] dx = {-1,1,0,0}, dy = {0,0,-1,1};
	static boolean[][] A = new boolean[16][16];
	static boolean[][] visited = new boolean[16][16];
	static boolean is_reachable = false;
	
	public static void dfs(int x, int y) {
		if(is_reachable) return;
		for(int i=0;i<4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx == x2 && ny == y2) {
				is_reachable = true;
				return;
			}
			if(nx >= 0 && nx < 16 && ny >= 0 && ny < 16 && !visited[nx][ny] && A[nx][ny]) {	
				visited[nx][ny] = true;
				dfs(nx, ny);
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		for(int t=1;t<=10;t++) {
			
			StringBuilder sb = new StringBuilder();
			sb.append("#" + t + " ");
			
			st = new StringTokenizer(br.readLine());
			
			for(int i=0;i<16;i++) {
				String s = br.readLine();
				for(int j=0;j<16;j++) {
					char c = s.charAt(j);
					if(c == '1') A[i][j] = false;
					else {
						if(c == '2') {
							x1 = i;
							y1 = j;
						}
						if(c == '3') {
							x2 = i;
							y2 = j;
						}
						A[i][j] = true;
					}
					
					visited[i][j] = false;
				}
			}
			
			is_reachable = false;
			
			visited[x1][y1] = true;
			dfs(x1,y1);
			
			if(is_reachable) sb.append(1);
			else sb.append(0);
			
			System.out.println(sb.toString());
		}
	}
}
