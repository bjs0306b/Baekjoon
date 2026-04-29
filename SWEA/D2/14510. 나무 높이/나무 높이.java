
import java.util.Scanner;

public class Solution {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		int t = sc.nextInt();
		for(int i=1;i<=t;i++) {
			int n = sc.nextInt();
			int A[] = new int[n];
			int mx = 0;
			for(int j=0;j<n;j++) {A[j] = sc.nextInt(); mx = Math.max(mx, A[j]);}
			int B[] = new int[n];
			for(int j=0;j<n;j++) B[j] = mx - A[j];
			
			int ans = 0;
			int sum = 0;
			int one_cnt = 0, temp = 1;
			for(int j=0;j<n;j++) {
				sum += B[j];
				if(B[j] == 0) continue;
				if(B[j] == 1) one_cnt++;
				else {
					if(B[j] % 2 == 0) temp += B[j]/2;
					else temp += (B[j] - 3)/2;
				}
				//System.out.println(B[j] + " " + one_cnt + " " + temp + " " + sum);
			}
			if(one_cnt > temp) { // 1이 너무 많아서 최적으로 해도 마지막에 1이 남음. temp - one_cnt가 남는 1의 양이고 2 1 2 1 로 채워야 되므로 남은 양 * 2 만큼 턴을 더 씀.
				ans += (one_cnt - temp) * 2;
				sum -= (one_cnt - temp);
			}
			ans += (sum / 3) * 2 + sum % 3;
			System.out.println("#" + i + " " + ans);
		}
	}

}
