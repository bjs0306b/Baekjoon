

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	
	static boolean is_number(String s) {
		try {
			Integer.parseInt(s);
			return true;
		}catch(Exception e) {
			return false;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for(int t=1;t<=10;t++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#" + t + " ");
			
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			
			boolean flag = true;
			for(int i=0;i<n;i++) {
				String[] s = br.readLine().split(" ");	
				if(is_number(s[1]) && s.length > 2 || !is_number(s[1]) && s.length == 2) flag = false;
			}
			if(flag) sb.append(1);
			else sb.append(0);
			
			System.out.println(sb.toString());
		}
	}
}
