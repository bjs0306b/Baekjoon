import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Solution {

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    String line = br.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            String s = next();
            if (s == null) return -1;
            return Integer.parseInt(s);
        }
    }

    public static void solve(int testIdx, FastScanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        if (n == -1 || m == -1) return;

        int[][] A = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(A[i], 1000000000);
        }

        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            a--; b--;
            A[a][b] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    A[j][k] = Math.min(A[j][i] + A[i][k], A[j][k]);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            boolean flag = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                // 정방향, 역방향 모두 도달 불가능한 경우
                if (A[i][j] == 1000000000 && A[j][i] == 1000000000) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }
        System.out.println("#" + testIdx + " " + ans);
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int t = sc.nextInt();
        if (t == -1) return;
        
        for (int i = 0; i < t; i++) {
            solve(i + 1, sc);
        }
    }
}
