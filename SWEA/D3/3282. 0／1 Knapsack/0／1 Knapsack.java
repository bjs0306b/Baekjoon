import java.util.Scanner;
public class Solution {
    static int n, m;
    static Scanner sc = new Scanner(System.in);

    static void solve(int test_idx) {
        n = sc.nextInt();
        m = sc.nextInt();
        
        // C++의 vector<int> dp(m+1, 0); 와 동일한 역할
        // 자바에서 정수형 배열은 할당 시 자동으로 0으로 초기화됩니다.
        int[] dp = new int[m + 1]; 

        for(int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            for(int j = m; j >= a; j--) {
                dp[j] = Math.max(dp[j], dp[j - a] + b);
            }
        }

        // C++의 *max_element(dp.begin(), dp.end()) 직역
        int ans = dp[0];
        for(int i = 1; i <= m; i++) {
            ans = Math.max(ans, dp[i]);
        }
        
        System.out.println("#" + test_idx + " " + ans);
    }

    public static void main(String[] args) {
        // C++의 cin.tie(0)->sync_with_stdio(0); 는 자바에서 적용되지 않으므로 제외했습니다.
        int t = sc.nextInt();
        for(int i = 0; i < t; i++) {
            solve(i + 1);
        }
    }
}