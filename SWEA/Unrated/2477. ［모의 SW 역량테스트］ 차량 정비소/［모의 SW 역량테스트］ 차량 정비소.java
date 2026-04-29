import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class Solution {
    static int n, m, k, a, b;
    static int[] receipt_time, maintenance_time, arrival_time;
    static Pair[] cur_receipt, cur_maintenance;
    
    // 제네릭 배열 생성을 우회하기 위해 배열로 선언 후 내부에서 초기화
    @SuppressWarnings("unchecked")
    static ArrayList<Integer>[] receipt_log = new ArrayList[10];
    @SuppressWarnings("unchecked")
    static ArrayList<Integer>[] maintenance_log = new ArrayList[10];
    
    static Queue<Integer> receipt_wait_queue = new LinkedList<>();
    static Queue<Integer> maintenance_wait_queue = new LinkedList<>();
    static Scanner sc = new Scanner(System.in);

    // C++의 pair<int, int> 역할을 대신할 내부 클래스
    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static void input() {
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();
        a = sc.nextInt();
        b = sc.nextInt();

        // C++ vector의 resize와 동일한 효과를 위해 배열을 생성
        receipt_time = new int[n + 1];
        cur_receipt = new Pair[n + 1];
        for (int i = 0; i <= n; i++) cur_receipt[i] = new Pair(0, 0);

        maintenance_time = new int[m + 1];
        cur_maintenance = new Pair[m + 1];
        for (int i = 0; i <= m; i++) cur_maintenance[i] = new Pair(0, 0);

        arrival_time = new int[k + 1];

        // 객체 배열 초기화
        for (int i = 0; i < 10; i++) {
            if (receipt_log[i] == null) receipt_log[i] = new ArrayList<>();
            if (maintenance_log[i] == null) maintenance_log[i] = new ArrayList<>();
        }

        for (int i = 1; i <= n; i++) {
            receipt_time[i] = sc.nextInt();
            receipt_log[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            maintenance_time[i] = sc.nextInt();
            maintenance_log[i].clear();
        }
        for (int i = 1; i <= k; i++) {
            arrival_time[i] = sc.nextInt();
        }
    }

    static void simulate() {
        int cur_customer_idx = 1;
        for (int i = 0; ; i++) {
            // 0. 시간이 흘렀으니 이걸 적용해서 현재 정비처 부터 남은 시간 1빼기.
            for (int j = 1; j <= m; j++) cur_maintenance[j].first--;

            // 1. 접수처도 남은 시간 1 빼기. 만약 0이 된 경우에는 정비 queue에 넣기
            for (int j = 1; j <= n; j++) {
                if (--cur_receipt[j].first == 0) {
                    maintenance_wait_queue.add(cur_receipt[j].second);
                }
            }

            // 2. 만약 현재 정비가 가능하다면 정비 queue에서 꺼내서 가능한 만큼 정비처에 넣기(log 남기기)
            for (int j = 1; j <= m; j++) {
                if (maintenance_wait_queue.isEmpty()) break;
                if (cur_maintenance[j].first <= 0) {
                    cur_maintenance[j] = new Pair(maintenance_time[j], maintenance_wait_queue.peek());
                    maintenance_log[j].add(maintenance_wait_queue.peek());
                    maintenance_wait_queue.poll();
                }
            }

            // 3. 현재 시간에 도착한 손님의 idx를 접수 queue에 넣기
            if (cur_customer_idx <= k) {
                while (i == arrival_time[cur_customer_idx]) {
                    receipt_wait_queue.add(cur_customer_idx);
                    ++cur_customer_idx;
                    if (cur_customer_idx == k + 1) break;
                }
            }

            // 4. 만약 현재 접수가 가능하다면 queue에서 꺼내서 가능한 만큼 접수처에 넣기(log 남기기)
            for (int j = 1; j <= n; j++) {
                if (receipt_wait_queue.isEmpty()) break;
                if (cur_receipt[j].first <= 0) {
                    cur_receipt[j] = new Pair(receipt_time[j], receipt_wait_queue.peek());
                    receipt_log[j].add(receipt_wait_queue.peek());
                    receipt_wait_queue.poll();
                }
            }

            // 5. 만약 2개의 queue가 전부 비어있고 모든 손님이 들어왔으며, 접수처 & 정비처의 사람이 없으면 종료.
            if (cur_customer_idx <= k) continue;
            boolean flag = true;
            if (!receipt_wait_queue.isEmpty()) flag = false;
            if (!maintenance_wait_queue.isEmpty()) flag = false;
            for (int j = 1; j <= n; j++) {
                if (cur_receipt[j].first > 0) {
                    flag = false;
                    break;
                }
            }
            for (int j = 1; j <= m; j++) {
                if (cur_maintenance[j].first > 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) break;
        }
    }

    static int find_user_sum() {
        int ret = 0;
        int[] cnt = new int[k + 1];
        
        // 향상된 for문(for-each)으로 vector<int> 순회와 동일하게 동작
        for (int kk : receipt_log[a]) {
            cnt[kk]++;
        }
        for (int kk : maintenance_log[b]) {
            cnt[kk]++;
        }

        for (int i = 1; i <= k; i++) {
            if (cnt[i] == 2) ret += i;
        }
        if (ret == 0) return -1;
        return ret;
    }

    static void solve(int test_idx) {
        simulate();
        int sum = find_user_sum();
        System.out.println("#" + test_idx + " " + sum);
    }

    public static void main(String[] args) {
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            input();
            solve(i + 1);
        }
    }
}