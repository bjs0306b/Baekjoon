import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

class group{
	int x, y, microbes, d;

	public group(int x, int y, int microbes, int d) {
		super();
		this.x = x;
		this.y = y;
		this.microbes = microbes;
		this.d = d;
	}
}

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
	static ArrayList<Integer> group_idx[][]; // 해당 위치에 있는 미생물들 idx 저장.
	static ArrayList<group> groups; // 군집들 정보
	static boolean is_dead[];
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int T=1;T<=t;T++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			
			group_idx = new ArrayList[n][n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					group_idx[i][j] = new ArrayList<>();
				}
			}
			groups = new ArrayList<>();
			is_dead = new boolean[k];
			
			for(int i=0;i<k;i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				int d = Integer.parseInt(st.nextToken()) - 1;
				
				group_idx[a][b].add(i);
				group g = new group(a,b,c,d);
				groups.add(g);
			}
			
			while(m-- > 0) {
				// 이동
				for(int i=0;i<k;i++) {
					if(is_dead[i]) continue;
					int x = groups.get(i).x;
					int y = groups.get(i).y;
					int microbes = groups.get(i).microbes;
					int d = groups.get(i).d;
					
					group_idx[x][y].remove(Integer.valueOf(i));
					
					int nx = x + dx[d] , ny = y + dy[d];
					if(nx == 0 || nx == n-1 || ny == 0 || ny == n-1) { // 약품 칠해진 곳으로 감.
						groups.get(i).microbes /= 2;
						if(groups.get(i).microbes == 0) {
							is_dead[i] = true; // 0 이면 사망
							continue; // group_idx에 추가 안하고 종료
						}
						if(d % 2 == 0) groups.get(i).d++;
						else groups.get(i).d--;
					}
					groups.get(i).x = nx;
					groups.get(i).y = ny;
					group_idx[nx][ny].add(i);
				}
				
				// 군집 합치기
				for(int i=0;i<n;i++) {
					for(int j=0;j<n;j++) {
						if(group_idx[i][j].size() > 1) { // 여러 군집이 한 셀에 모임
							int mx = 0;
							int mx_idx = -1;
							for(int idx : group_idx[i][j]) { // 미생물이 가장 많은 군집 찾기
								if(mx < groups.get(idx).microbes) {
									mx = groups.get(idx).microbes;
									mx_idx = idx;
								}
							}
							
							for(int idx : group_idx[i][j]) {
								if(is_dead[idx]) continue;
								if(idx != mx_idx) {
									is_dead[idx] = true;
									groups.get(mx_idx).microbes += groups.get(idx).microbes;
									groups.get(idx).microbes = 0;
								}
							}
						}
					}
				}
				
//				for(int i=0;i<k;i++) {
//					System.out.println(groups.get(i).x + " " + groups.get(i).y + " " + groups.get(i).microbes + " " + groups.get(i).d + " ");
//				}
//				for(int i=0;i<k;i++) {
//					if(!is_dead[i]) System.out.print(i);
//				}
//				System.out.println();
			}
			
			int ans = 0;
			for(int i=0;i<k;i++) {
				if(!is_dead[i]) {
					ans += groups.get(i).microbes;
				}
			}

			System.out.println("#" + T + " " + ans);
		}
	}
}
