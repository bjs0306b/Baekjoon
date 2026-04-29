import java.util.Scanner;


public class Solution {
    static int n, m, k;
    static int[][] A = new int[13][20];
    static int[] change = new int[13]; // 해당 행 바꾸기, 0 : 안바꿈, 1 : A로 바꿈, 2 : B로 바꿈
    static int ans;
    static Scanner sc = new Scanner(System.in);

    static void input() {
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();
        ans = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++) {
            change[i] = 0;
            for(int j = 0; j < m; j++) {
                A[i][j] = sc.nextInt();
            }
        }
    }

    static boolean check() {
        int[][] B = new int[n][m];
        for(int i = 0; i < n; i++) {
            if(change[i] == 0) {
                for(int j = 0; j < m; j++) B[i][j] = A[i][j];
            } else {
                for(int j = 0; j < m; j++) B[i][j] = change[i] - 1;
            }
        }

        for(int i = 0; i < m; i++) {
            boolean flag = false;
            int cnt = 1;
            for(int j = 1; j < n; j++) {
                if(B[j][i] == B[j-1][i]) {
                    cnt++;
                    if(cnt == k) {
                        flag = true;
                        break;
                    }
                } else {
                    cnt = 1;
                }
            }
            if(!flag) return false;
        }
        return true;
    }

    static void dfs(int dep, int change_cnt) {
        if(ans <= change_cnt) return;
        if(dep == n) {
            if(check()) ans = Math.min(ans, change_cnt);
            return;
        }

        change[dep] = 0;
        dfs(dep + 1, change_cnt);
        change[dep] = 1;
        dfs(dep + 1, change_cnt + 1);
        change[dep] = 2;
        dfs(dep + 1, change_cnt + 1);
    }

    static void solve(int test_index) {
        System.out.print("#" + test_index + " ");
        if(k == 1) {
            System.out.println("0");
            return;
        }
        dfs(0, 0);
        System.out.println(ans);
    }

    public static void main(String[] args) {
        // C++의 cin.tie(0)->sync_with_stdio(0); 는 자바에서 무효한 개념이므로 생략했습니다.
        int t = sc.nextInt();
        for(int i = 0; i < t; i++) {
            input();
            solve(i + 1);
        }
    }
}