import java.util.Scanner;
import java.util.ArrayList;
import java.io.FileInputStream;

class Solution
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t=1;t<=T;t++) {
			int n = sc.nextInt();
			String[] s = new String[n];
			for(int i=0;i<n;i++) {
				s[i] = sc.next();
			}
			
			String[] ans = new String[n];
			
			for(int i=0;i<(n+1)/2;i++) 
				ans[i*2] = s[i];
			
			int idx = 1;
			for(int i=(n+1)/2;i<n;i++) {
				ans[idx] = s[i];
				idx+=2;
			}
			
			System.out.print("#"+ t + " ");
			for(int i=0;i<n;i++) {
				System.out.print(ans[i] + " ");
			}
			System.out.println();
		}
	}
}