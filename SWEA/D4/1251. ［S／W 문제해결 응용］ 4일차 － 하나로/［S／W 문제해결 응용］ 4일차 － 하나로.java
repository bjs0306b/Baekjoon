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
			System.out.print("#" + T + " ");
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());

			long xs[] = new long[n], ys[] = new long[n];
			
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				xs[i] = Long.parseLong(st.nextToken());	
			}
			
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				ys[i] = Long.parseLong(st.nextToken());	
			}
			
			
			st = new StringTokenizer(br.readLine());
			double d = Double.parseDouble(st.nextToken());
			double ans = 0;
			
			boolean[] visited = new boolean[n];
			long[] dis = new long[n];
			for(int i=0;i<n;i++) dis[i] = Long.MAX_VALUE;
			dis[0] = 0;
			
			for(;;){
				int min_idx = -1;
				long min = Long.MAX_VALUE;
				for(int i=0;i<n;i++) {
					if(visited[i]) continue;
					if(min > dis[i]) {
						min = dis[i];
						min_idx = i;
					}
				}
				if(min_idx == -1) break; // 다 방문
				
				ans += min;
				visited[min_idx] = true;
				
				for(int i=0;i<n;i++) {
					if(visited[i]) continue;
					dis[i] = Math.min(dis[i], (xs[i] - xs[min_idx])*(xs[i] - xs[min_idx]) + (ys[i] - ys[min_idx])*(ys[i] - ys[min_idx]));
				}
			}
			
			
			ans *= d;

			System.out.println(Math.round(ans));
		}
	}
}
