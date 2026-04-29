import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Arrays;


public class Solution {
    
    // [사실] C++의 cin 로직을 완벽히 흉내 내기 위한 클래스
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
                    if (line == null) return null; // 입력이 끝났을 때의 안전 처리
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
        if (n == -1) return; // 안전 종료

        ArrayList<int[]>[] v = new ArrayList[n + 1];
        for (int i = 0; i < n; i++) {
            v[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int temp = sc.nextInt();
                if (temp == 1) {
                    v[i].add(new int[]{1, j});
                }
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int[] dis = new int[n];
            Arrays.fill(dis, 1000000000);
            
            PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
            
            dis[i] = 0;
            pq.offer(new int[]{0, i});
            
            while (!pq.isEmpty()) {
                int[] f = pq.poll();
                int curDis = f[0];
                int curNode = f[1];
                
                if (dis[curNode] < curDis) continue;
                
                for (int[] k : v[curNode]) {
                    int cost = k[0];
                    int nextNode = k[1];
                    
                    if (dis[nextNode] > dis[curNode] + cost) {
                        dis[nextNode] = dis[curNode] + cost;
                        pq.offer(new int[]{dis[nextNode], nextNode});
                    }
                }
            }

            // 주의: 도달 불가능한 노드가 많을 경우 sum이 오버플로우 될 수 있습니다.
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += dis[j];
            }
            ans = Math.min(ans, sum);
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