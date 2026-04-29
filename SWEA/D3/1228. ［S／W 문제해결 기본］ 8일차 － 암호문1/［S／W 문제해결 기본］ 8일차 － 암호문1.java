import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		for(int T=1;T<=10;T++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#" + T + " ");
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			
			st = new StringTokenizer(br.readLine());
			
			ArrayList<String> A = new ArrayList<>();
			for(int i=0;i<n;i++) A.add(st.nextToken());
			
			st = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<m;i++) {
				String c = st.nextToken();
				if(c.equals("I")) {
					int x = Integer.parseInt(st.nextToken());
					int y = Integer.parseInt(st.nextToken());
					
					for(int j=0;j<y;j++) {
						String temp = st.nextToken();
						
						A.add(x+j, temp);
					}
				}
			}
			
			for(int i=0;i<10;i++) sb.append(A.get(i) + " ");
			
			System.out.println(sb.toString());
		}
	}
}
