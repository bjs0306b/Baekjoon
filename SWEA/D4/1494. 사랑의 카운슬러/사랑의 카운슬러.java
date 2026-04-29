import java.io.*;
import java.util.*;

public class Solution {
    static class Point {
        long x, y;
        Point(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }

    static int n;
    static long ans;
    static Point[] v;
    static boolean[] visited;
    
    static BufferedReader br;
    static StringTokenizer st;

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    static void input() throws IOException {
        n = Integer.parseInt(next());
        v = new Point[n];
        visited = new boolean[20];
        ans = Long.MAX_VALUE; 
        
        for (int i = 0; i < n; i++) {
            long a = Long.parseLong(next());
            long b = Long.parseLong(next());
            v[i] = new Point(a, b);
        }
    }

    
    static void dfs(int dep, int s) {
        if (dep == n / 2) {
            long x_sum = 0, y_sum = 0;
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    x_sum += v[i].x;
                    y_sum += v[i].y;
                } else {
                    x_sum -= v[i].x;
                    y_sum -= v[i].y;
                }
            }
            long dis = x_sum * x_sum + y_sum * y_sum;
            ans = Math.min(ans, dis);
            return;
        }

        for (int i = s; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            dfs(dep + 1, i + 1);
            visited[i] = false;
        }
    }

    static void solve(int test_idx) {
        dfs(0, 0);
        System.out.println("#" + test_idx + " " + ans);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        String tStr = next();
        if (tStr == null) return;
        int t = Integer.parseInt(tStr);
        
        for (int i = 0; i < t; i++) {
            input();
            solve(i + 1);
        }
    }
}