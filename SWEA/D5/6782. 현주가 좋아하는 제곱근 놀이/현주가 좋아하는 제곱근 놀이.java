
import java.util.Scanner;
import java.util.TreeSet;

public class Solution {
	static Scanner sc = new Scanner(System.in);
	static TreeSet<Long> st = new TreeSet<>();
	
	static int solve() {
		Long n = sc.nextLong();
		if(n == 1) return 1;
		if(n == 2) return 0;
		int ret = 0;
		while(n != 2) {
			Long temp = st.ceiling(n);
			ret += (temp - n + 1);
			n = (long) Math.sqrt(temp);
		}
		return ret;
	}
	
	public static void main(String[] args) {
	
		for(long i=1;i<=1000000;i++) {
			st.add(i*i);
		}
		
		int t = sc.nextInt();
		for(int i=1;i<=t;i++) {
			System.out.print("#" + i + " ");
			System.out.println(solve());
		}
	}
}
