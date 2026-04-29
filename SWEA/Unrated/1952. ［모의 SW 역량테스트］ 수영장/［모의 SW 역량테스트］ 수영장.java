import java.util.Scanner;

public class Solution {
    static int[] price = new int[4];
    static int[] month_cnt = new int[13];
    static int[] dp = new int[13]; // i 월까지의 최소값
    static Scanner sc = new Scanner(System.in);

    static void input() {
        for(int i = 0; i < 4; i++) price[i] = sc.nextInt();
        for(int i = 1; i <= 12; i++) month_cnt[i] = sc.nextInt();
        dp[0] = 0;
        for(int i = 1; i <= 12; i++) dp[i] = 1000000000;
    }

    static void print() {
        for(int i = 1; i <= 12; i++) System.out.print(dp[i] + " ");
        System.out.println();
    }

    static void solve(int test_idx) {
        for(int i = 1; i <= 12; i++) {
            dp[i] = Math.min(dp[i], dp[i-1] + month_cnt[i] * price[0]); // 일일 이용권

            if(month_cnt[i] > 0) {
                dp[i] = Math.min(dp[i], dp[i-1] + price[1]); // 월간 이용권
                if(i > 2) dp[i] = Math.min(dp[i], dp[i-3] + price[2]); // 3개월 이용권
            } else {
                dp[i] = Math.min(dp[i], dp[i-1]);
            }
        }

        int ans = Math.min(price[3], dp[12]); // 연간 이용권
        System.out.println("#" + test_idx + " " + ans);
    }

    public static void main(String[] args) {
        // C++의 cin.tie(0)->sync_with_stdio(0); 부분은 I/O 최적화 코드이므로,
        // 자바 직역 시에는 영향을 주지 않아 일반 Scanner 환경으로 구현되었습니다.
        int t = sc.nextInt();
        for(int i = 0; i < t; i++) {
            input();
            solve(i + 1);
        }
    }
}