import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Solution {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static long to_decimal(String s) {
		long ret = 0;
		long temp = 1;
		for(int i=s.length()-1;i>=0;i--) {
			long c;
			if(s.charAt(i) >= '0' && s.charAt(i) <= '9') c = s.charAt(i) - '0';
			else c = s.charAt(i) - 'A' + 10;
			ret += temp * c;
			temp *= 16;
		}
		return ret;
	}
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		for(int T=1;T<=t;T++) {
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			String s = br.readLine();
			TreeSet<Long> st = new TreeSet<>();
			
			for(int k=0;k<n/4;k++) { // 회전 
				for(int i=0;i<4;i++) {
					String temp = "";
					for(int j=i*n/4;j<(i+1)*n/4;j++) {
						temp += s.charAt(j);
					}
					
					long d = to_decimal(temp);
//					System.out.println(temp + " " + d);
					st.add(d);
				}
				
				s = s.charAt(n - 1) + s.substring(0, n - 1);
			}
			
			int cnt = st.size() - m;
			for(long kk : st) {		
				if(cnt-- == 0) {
					System.out.println("#" + T + " " + kk);
					break;
				}
			}
		}
	}
}
