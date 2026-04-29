
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n;
	 // (x,y)에 위치하는 원자 번호 저장. 번호는 1부터 시작하고 0 이면 비어있는 거.
	static int [][] cur_atom = new int[4001][4001];
	static int[][] atoms ; // 원자들 정보 저장.
	static int[] dx = {0,0,-1,1}, dy = {1,-1,0,0};
	static boolean[] is_dead;

	public static void input() throws IOException {
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		atoms = new int[n][4];
		is_dead = new boolean[n];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<4;j++) atoms[i][j]= Integer.parseInt(st.nextToken());
			atoms[i][0] += 1000; // -1000 ~ 1000 -> 0 ~ 2000 으로 보정.
			atoms[i][0] *= 2; // 칸 중간에서 만나는 경우를 고려해 0~4000 으로 보정하고 이동할 때 0.5초씩 이동.
			atoms[i][1] += 1000;
			atoms[i][1] *= 2;
		}	
	}
	

	public static void solve() {
		int ans = 0;
		int cnt = n;
		while(cnt > 0) {
			for(int i=0;i<n;i++) {
				if(is_dead[i]) continue;
				int x = atoms[i][0], y = atoms[i][1], d = atoms[i][2];
				int nx = x + dx[d], ny = y + dy[d];
				if(!(nx >= 0 && nx <= 4000 && ny >= 0 && ny <= 4000)) {
					// 벗어나면 다시는 돌아올 수 없고 다른 원자를 만날 일도 없음.
					cnt--;
					is_dead[i] = true;
					continue;
				}
				// 그냥 이동
				atoms[i][0] = nx;
				atoms[i][1] = ny;
			}
			for(int i=0;i<n;i++) {
				if(is_dead[i]) continue;
				int x = atoms[i][0], y = atoms[i][1];
				
				if(cur_atom[x][y] > 0) {	
					// 처음 충돌
					if(!is_dead[cur_atom[x][y]-1]) {
						is_dead[cur_atom[x][y]-1] = true;
						cnt--;
						ans += atoms[cur_atom[x][y]-1][3];
					}
					
					cnt--;
					ans += atoms[i][3];
					is_dead[i] = true;
				}
				else {
					cur_atom[x][y] = i+1;
				}
			}
			for(int i=0;i<n;i++) {
				int x = atoms[i][0], y = atoms[i][1];
				if(x >= 0 && x <= 4000 && y >= 0 && y <= 4000) cur_atom[x][y] = 0;
			}
		}
		System.out.println(ans);
	}
		
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		
		for(int i=1;i<=t;i++) {
			System.out.print("#" + i + " ");
			input();
			solve();
		}
	}

}