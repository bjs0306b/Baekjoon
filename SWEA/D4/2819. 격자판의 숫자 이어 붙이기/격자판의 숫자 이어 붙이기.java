import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static HashSet<String> hs;
	static int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
	static String A[][];
	
	static void dfs(int x, int y, int dep, String temp) {
		if(dep == 6) {
			hs.add(temp);
			return;
		}
		for(int i=0;i<4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4) dfs(nx, ny, dep+1, temp + A[nx][ny]);
		}
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int T=1;T<=t;T++) {
			A = new String[4][4];
			hs = new HashSet<>();
			for(int i=0;i<4;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0;j<4;j++) A[i][j] = st.nextToken();
			}
			
			for(int i=0;i<4;i++) {
				for(int j=0;j<4;j++) {
					dfs(i, j, 0, A[i][j]);
				}
			}
			System.out.println("#" + T + " " + hs.size());
		}
	}
}
