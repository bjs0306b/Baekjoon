

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int[] Acard = new int[9];
	static int[] Bcard = new int[9];
	static ArrayList<Integer> usable_card = new ArrayList<Integer>();
	static int w, d, l;
	static StringTokenizer st;
	static boolean[] visited = new boolean[9];
	
	
	static void dfs(int n) {
		if(n == 9) {
			int A_score = 0;
			int B_score = 0;
			for(int i=0;i<9;i++) {
				if(Acard[i] > Bcard[i]) A_score += (Acard[i] + Bcard[i]);
				else if(Acard[i] < Bcard[i]) B_score += (Acard[i] + Bcard[i]);
			}
			if(A_score > B_score) w++;
			else if(A_score < B_score) l++;
			else d++;
			
			return;
		}
		
		for(int i=0;i<9;i++) {
			if(visited[i]) continue;
			Bcard[n] = usable_card.get(i);
			visited[i] = true;
			dfs(n+1);
			visited[i] = false;
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int i=1;i<=t;i++) {
			w = l = d = 0;
			for(int j=0;j<9;j++) visited[j] = false;
			st = new StringTokenizer(br.readLine());
			usable_card.clear();
			
			boolean[] is_used = new boolean[19];
			for(int j=0;j<19;j++) is_used[j] = false;
			
			for(int j=0;j<9;j++) {
				Acard[j] = Integer.parseInt(st.nextToken());
				is_used[Acard[j]] = true;
			}
			
			for(int j=1;j<19;j++) {
				if(!is_used[j]) {
					usable_card.add(j);
				}
			}
			
			dfs(0);
			
			System.out.println("#" + i + " " + w + " " + l);
		}
	}
}
