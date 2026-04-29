import java.io.*;
import java.util.*;
public class Solution {
    static String a, b;
    static int[] table;
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
        a = next();
        b = next();
    }

    static void make_table() {
        int b_size = b.length();
        table = new int[b_size]; 
        int j = 0;
        
        for (int i = 1; i < b_size; i++) {
            while (j > 0 && b.charAt(i) != b.charAt(j)) {
                j = table[j - 1];
            }
            if (b.charAt(i) == b.charAt(j)) {
                table[i] = ++j;
            }
        }
    }

    static void solve(int test_idx) {
        make_table();

        int a_size = a.length();
        int b_size = b.length();
        int a_point = 0, b_point = 0, ans = 0;

        for (; a_point < a_size; a_point++) {
            while (b_point > 0 && a.charAt(a_point) != b.charAt(b_point)) {
                b_point = table[b_point - 1];
            }
            if (a.charAt(a_point) == b.charAt(b_point)) {
                if (b_point == b_size - 1) {
                    ans++;
                    b_point = table[b_point];
                } else {
                    b_point++;
                }
            }
        }
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