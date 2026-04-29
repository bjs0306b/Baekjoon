import java.util.*;

public class Solution {
    static int n;
    static int[][] A = new int[10][10];
    static int[][] dis = new int[10][2]; 
    static int stair_idx, human_cnt;
    static int[] down_time = new int[2];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            input(sc);
            solve(i + 1);
        }
    }

    static void input(Scanner sc) {
        n = sc.nextInt();
        int[][] stairs = new int[2][2];
        stair_idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = sc.nextInt();
                if (A[i][j] > 1) {
                    down_time[stair_idx] = A[i][j];
                    stairs[stair_idx][0] = i;
                    stairs[stair_idx][1] = j;
                    stair_idx++;
                }
            }
        }
        human_cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    dis[human_cnt][0] = Math.abs(i - stairs[0][0]) + Math.abs(j - stairs[0][1]);
                    dis[human_cnt][1] = Math.abs(i - stairs[1][0]) + Math.abs(j - stairs[1][1]);
                    human_cnt++;
                }
            }
        }
    }

    static void solve(int test_idx) {
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < (1 << human_cnt); i++) {
            // C++의 deque 대신 인덱스 접근이 자유로운 LinkedList 사용
            LinkedList<Integer> first_stair = new LinkedList<>();
            LinkedList<Integer> second_stair = new LinkedList<>();

            for (int j = 0; j < human_cnt; j++) {
                if ((i & (1 << j)) != 0) {
                    first_stair.add(dis[j][0]);
                } else {
                    second_stair.add(dis[j][1]);
                }
            }

            Collections.sort(first_stair);
            Collections.sort(second_stair);

            // 계단 시뮬레이션용 리스트 (dq1, dq2)
            ArrayList<Integer> dq1 = new ArrayList<>();
            ArrayList<Integer> dq2 = new ArrayList<>();
            int cur_time1 = 0, cur_time2 = 0;

            // Stair 1 시뮬레이션
            for (;; cur_time1++) {
                for (int j = 0; j < dq1.size(); j++) {
                    dq1.set(j, dq1.get(j) + 1);
                }

                while (!dq1.isEmpty() && dq1.get(0) == down_time[0]) {
                    dq1.remove(0);
                }

                while (!first_stair.isEmpty() && cur_time1 >= first_stair.get(0) && dq1.size() < 3) {
                    if (cur_time1 > first_stair.get(0)) dq1.add(0);
                    else dq1.add(-1);
                    first_stair.remove(0);
                    if (first_stair.isEmpty()) break;
                }

                if (first_stair.isEmpty() && dq1.isEmpty()) break;
            }

            // Stair 2 시뮬레이션
            for (;; cur_time2++) {
                for (int j = 0; j < dq2.size(); j++) {
                    dq2.set(j, dq2.get(j) + 1);
                }

                while (!dq2.isEmpty() && dq2.get(0) == down_time[1]) {
                    dq2.remove(0);
                }

                while (!second_stair.isEmpty() && cur_time2 >= second_stair.get(0) && dq2.size() < 3) {
                    if (cur_time2 > second_stair.get(0)) dq2.add(0);
                    else dq2.add(-1);
                    second_stair.remove(0);
                    if (second_stair.isEmpty()) break;
                }

                if (second_stair.isEmpty() && dq2.isEmpty()) break;
            }

            ans = Math.min(ans, Math.max(cur_time1, cur_time2));
        }
        System.out.println("#" + test_idx + " " + ans);
    }
}