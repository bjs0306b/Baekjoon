import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
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
			int m = Integer.parseInt(st.nextToken());
			ArrayList<int[]>[] v = new ArrayList[n];
			for(int i=0;i<n;i++) v[i] = new ArrayList<>();
			
			for(int i=0;i<m;i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				a--;
				b--;
				v[a].add(new int[]{b,c});
				v[b].add(new int[]{a,c});
			}	
			

			long ans = 0;
			
			boolean[] visited = new boolean[n];
			PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2)->Long.compare(o1[1], o2[1]));
			pq.add(new int[] {0,0});
			int cnt = n;
			while(cnt > 0) {
				int[] tp = pq.poll();
				if(visited[tp[0]]) continue;
				
				ans += tp[1];
				cnt--;
				visited[tp[0]] = true;
				
				for(int[] k : v[tp[0]]) {
					if(!visited[k[0]]) {
						pq.add(k);
					}
				}
			}

			System.out.println(ans);
		}
	}
}
