

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int[][] A = new int[100][100];

	public static void input() throws IOException {
		for(int i=0;i<100;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<100;j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	
	public static void dfs(int x, int y, int pre_x, int pre_y, int start) {
		if(A[x][y] == 2) {
			sb.append(start);
			return;
		}
		
		if(y > 0 && A[x][y-1] == 1 && !(x == pre_x && y-1 == pre_y)) {
			dfs(x,y-1, x,y,start);
		}
		else if(y < 99 && A[x][y+1] == 1 && !(x == pre_x && y+1 == pre_y)) {
			dfs(x,y+1, x,y,start);
		}
		else{
			if(x+1 < 100) dfs(x+1, y, x,y,start);
		}
	}
	
	public static void solve() {
		for(int i=0;i<100;i++) {
			if(A[0][i] == 1) {
				dfs(0,i, -1,-1, i);
			}
		}
		System.out.println(sb.toString());
		sb = new StringBuilder();
	}
	
	public static void main(String[] args) throws IOException {
	
		for(int t=1;t<=10;t++) {
			st = new StringTokenizer(br.readLine());
			sb.append("#" + t + " ");
			input();
			solve();
		}
		
		
	}

}
