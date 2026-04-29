
import java.util.HashMap;
import java.util.Scanner;

public class Solution {
	
	static Scanner sc = new Scanner(System.in);
	static HashMap<String, Integer> mp = new HashMap<>();

	static int split(String n, int dep,  int bit) {
		if(mp.containsKey(n)) return mp.get(n);
		if(n.length() <= 1) return 0;
		if(dep == n.length()-1) {
			if(bit == 0) return 0;
			
			int multi = 1;
			
			int temp = 0;
			for(int i=0;i<n.length()-1;i++) {
				if((bit & (1<<i)) != 0) {
					int num = Integer.parseInt(n.substring(temp, i+1));
					multi *= num;
					temp = i+1;
				}
			}
			multi *= Integer.parseInt(n.substring(temp, n.length()));
			String s = String.valueOf(multi);
			
			int ret = split(s, 0, 0);
			mp.put(s, ret);
			return ret + 1;
		}
		int ret = Math.max(split(n, dep+1, bit), split(n, dep+1, bit|(1<<dep)));;
		return ret;
	}

	
	public static void main(String[] args) {
		int t = sc.nextInt();
		for(int i=1;i<=t;i++) {
			String s = sc.next();
			int ans = split(s, 0, 0);
			System.out.println("#" + i + " " + ans);
		}
	}

}
