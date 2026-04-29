

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n;
	static int[] mn, price, month, period;
	
	public static void input() throws IOException {
		mn = new int[13];
		price = new int[4];
		month = new int[13];
		period = new int[]{0,1,3,12};
		
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<4;i++) price[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=1;i<=12;i++) {
			month[i] = Integer.parseInt(st.nextToken());
			mn[i] = Integer.MAX_VALUE;
		}
		mn[0] = 0;
	}
	
	static void dfs(int dep, int sum) {
		if(dep > 12 || mn[dep] < sum) return;
		mn[dep] = Math.min(mn[dep], sum);
		if(dep == 12) return;
		
		for(int i=1;i<4;i++) {
			if(i == 1 ) dfs(dep+period[i], sum + Math.min(price[i], price[0]*month[dep+1]));
			else dfs(dep+period[i], sum+price[i]);
		}
	}
	
	public static void solve() {
		dfs(0, 0);
		System.out.println(mn[12]);
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
