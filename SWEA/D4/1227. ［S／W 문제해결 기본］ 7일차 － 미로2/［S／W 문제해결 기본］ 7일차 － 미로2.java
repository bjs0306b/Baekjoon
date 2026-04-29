
import java.util.Scanner;

public class Solution {
	
	static char[][] A;
	static boolean[][] visited;
	static boolean is_correct;
	static int start_x, start_y, end_x, end_y;
	static int[] dx = {-1,1,0,0}, dy = {0,0,-1,1};
	static Scanner sc = new Scanner(System.in);
	
	
	static void dfs(int x, int y) {
		if(is_correct) return;
		for(int i=0;i<4;i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < 100 & ny >= 0 && ny < 100 && !visited[nx][ny] && A[nx][ny] == '0') {
				if(nx == end_x && ny == end_y) {
					is_correct = true;
					return;
				}
				visited[nx][ny] = true;
				dfs(nx, ny);
			}
		}
	}
	
	public static void main(String[] args) {
		for(int t=1;t<=10;t++) {
			int num = sc.nextInt();
			is_correct = false;
			A = new char[100][100];
			visited = new boolean[100][100];
			for(int i=0;i<100;i++) {
				String s = sc.next();
				for(int j=0;j<100;j++) {
					A[i][j] = s.charAt(j);
					if(A[i][j] == '2') {
						start_x = i;
						start_y = j;
						A[i][j] = '0';
					}
					else if(A[i][j] == '3') {
						end_x = i;
						end_y = j;
						A[i][j] = '0';
					}
				}
			}
			visited[start_x][start_y] = true;
			dfs(start_x, start_y);
			if(is_correct) System.out.println("#" + t + " 1");
			else  System.out.println("#" + t + " 0");
		}
	}

}
