import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Solution {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0,-1,1};
	static int bfs() throws IOException {
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] cur_pos = new int[2];
		int[][] A = new int[n][m];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				A[i][j] = Integer.parseInt(st.nextToken());
				if(A[i][j] == 3) {
					cur_pos[0] = i;
					cur_pos[1] = j;
					A[i][j] = 0;
				}
				//System.out.print(A[i][j] + " ");
			}
			//System.out.println();
		}
		
		boolean[][] visited = new boolean[n][m];
		ArrayDeque<int[]> q = new ArrayDeque<>();
		q.add(cur_pos);
		visited[cur_pos[0]][cur_pos[1]] = true;
		int cnt = 1;
		while(!q.isEmpty()) {
			// 독가스 퍼짐
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(A[i][j] == 2) {
						for(int k=0;k<4;k++) {
							int nx = i + dx[k];
							int ny = j + dy[k];
							if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == 0) {
								A[nx][ny] = 4;
							}
						}
					}
				}
			}
			
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(A[i][j] == 4) A[i][j] = 2;
				}
			}
			
			int size = q.size();
			for(int i=0;i<size;i++) {
				int[] f = q.poll();
				
				for(int j=0;j<4;j++) {
					int nx = f[0] + dx[j], ny = f[1] + dy[j];
					//System.out.println(nx + " " + ny);
					if(nx >= 0 && nx < n && ny >= 0 && ny < m){
						if(!visited[nx][ny] && A[nx][ny] == 0) {
							visited[nx][ny] = true;
							int[] np = new int[2];
							np[0] = nx; np[1] = ny;
							q.add(np);
						}
					}
					else { // 탈출
						return cnt;
					}
				}
				
			}
			cnt++;
		}
		
		// 독가스 퍼짐
		for(;;) {
			boolean flag = true;
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if(A[i][j] == 2) {
						for(int k=0;k<4;k++) {
							int nx = i + dx[k];
							int ny = j + dy[k];
							if(nx >= 0 && nx < n && ny >= 0 && ny < m && A[nx][ny] == 0) {
								A[nx][ny] = 2;
								flag = false;
							}
						}
					}
				}
			}
			if(flag) break;
		}
		// 독가스가 전부 퍼졌을 때 시작 위치에 도착할 수 있으면 독가스로 인해 못나간 거임.
		if(A[cur_pos[0]][cur_pos[1]] == 2) return -2;
		return -1;
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		
		for(int T=1;T<=t;T++) {
			System.out.print("#" + T + " ");
			int temp = bfs();
			if(temp == -1) { // 그냥 탈출 불가
				System.out.println("CANNOT ESCAPE");
			}
			else if(temp == -2) { // 좀비
				System.out.println("ZOMBIE");
			}
			else { // 탈출
				System.out.println(temp);
			}
		}
		
	}

}
