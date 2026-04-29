
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
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
			int m = Integer.parseInt(st.nextToken());
			parent = new int[n+1];
			for(int i=1;i<=n;i++) parent[i] = i;
			
			for(int i=0;i<m;i++) {
				st = new StringTokenizer(br.readLine());
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				int p1 = find(b), p2 = find(c);
				if(p1 > p2) {
					int temp = p1;
					p1 = p2;
					p2 = temp;
				}
				parent[p1] = p2;
			}
			
			Set<Integer> st = new HashSet<>();
			for(int i=1;i<=n;i++) {
				st.add(find(i));
			}

			System.out.println(st.size());
		}
	}
}
