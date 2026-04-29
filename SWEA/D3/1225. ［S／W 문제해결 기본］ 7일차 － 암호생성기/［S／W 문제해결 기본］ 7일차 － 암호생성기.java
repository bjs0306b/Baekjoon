import java.util.ArrayDeque;
import java.util.Scanner;

class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int t=1;t<=10;t++) {
			int n; n = sc.nextInt();
			ArrayDeque<Integer> dq = new ArrayDeque<>();
			
			for(int i=0;i<8;i++) {
				int num = sc.nextInt();
				dq.addLast(num);
			}
			
			for(;;) {
				boolean flag = false;
				for(int i=1;i<=5;i++) {
					int f = dq.getFirst();
					dq.pop();
					
					if(f - i > 0) {
						dq.addLast(f-i);
					}
					else {
						dq.addLast(0);
						flag = true;
						break;
					}
				}
				if(flag) break;
			}
			
			System.out.print("#" + t + " ");
			
			for(Integer k : dq) {
				System.out.print(k + " ");
			}
			System.out.println();
		}
		
	}
}
