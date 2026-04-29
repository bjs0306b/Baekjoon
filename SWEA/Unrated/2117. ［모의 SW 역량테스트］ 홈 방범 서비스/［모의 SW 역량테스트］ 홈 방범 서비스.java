import java.util.Scanner;
public class Solution {
    static int n, m;
    static int[][] A = new int[20][20];
    static Scanner sc = new Scanner(System.in);

    static void input() {
        n = sc.nextInt();
        m = sc.nextInt();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                A[i][j] = sc.nextInt();
            }
        }
    }

    static int counting(int x, int y, int k) {
        int cnt = 0;
        for(int i = -k; i <= k; i++) {
            for(int j = -k; j <= k; j++) {
                if(Math.abs(i) + Math.abs(j) > k) continue;
                int nx = x + i, ny = y + j;
                if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if(A[nx][ny] == 1) cnt++;
                }
            }
        }
        return cnt;
    }

    static void solve(int test_idx) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 1; k <= n + 2; k++) {
                    int temp = counting(i, j, k - 1);
                    
                    if(temp * m - (k * k + (k - 1) * (k - 1)) >= 0) {
                        // System.out.println(i + " " + j + " " + k + " " + temp);
                        ans = Math.max(ans, temp);
                    }
                }
            }
        }
        System.out.println("#" + test_idx + " " + ans);
    }

    public static void main(String[] args) {
        // C++의 cin.tie(0)->sync_with_stdio(0); 부분은 무시됩니다.
        int t = sc.nextInt();
        for(int i = 0; i < t; i++) {
            input();
            solve(i + 1);
        }
    }
}