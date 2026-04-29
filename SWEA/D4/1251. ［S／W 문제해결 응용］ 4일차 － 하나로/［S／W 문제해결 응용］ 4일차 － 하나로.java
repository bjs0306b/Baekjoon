import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int[] parent;
	
	static int find(int a) {
		if(parent[a] == a) return a;
		return parent[a] = find(parent[a]);
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		
		for(int T=1;T<=t;T++) {
			System.out.print("#" + T + " ");
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			parent = new int[n];
			for(int i=0;i<n;i++) parent[i] = i;
			
			PriorityQueue<long[]> pq = new PriorityQueue<>((o1, o2) -> Long.compare(o1[0], o2[0]));
			
			
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
			
			for(int i=0;i<n-1;i++) {
				for(int j=i+1;j<n;j++) {
					long[] temp = new long[3];
					temp[0] = (xs[i] - xs[j])*(xs[i] - xs[j]) + (ys[i] - ys[j])*(ys[i] - ys[j]);
					temp[1] = i;
					temp[2] = j;
					pq.add(temp);
				}
			}
			
			int cnt = n-1;
			double ans = 0;
			while(cnt > 0) {
				long[] tp = pq.poll();
				int p1 = find((int)tp[1]), p2 = find((int)tp[2]);
				if(p1 == p2) continue;
				
				if(p1 > p2) {
					int temp = p1;
					p1 = p2;
					p2 = temp;
				}
				
				parent[p1] = p2;
				
				cnt--;
				ans += d * (double)tp[0];
			}
			System.out.println(Math.round(ans));
		}
	}
}
