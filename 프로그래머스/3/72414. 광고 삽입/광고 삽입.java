import java.util.*;

class Solution {
    
    int str_to_sec(String s){
        int hh = Integer.parseInt(s.substring(0, 2));
        int mm = Integer.parseInt(s.substring(3, 5));
        int ss = Integer.parseInt(s.substring(6, 8));
        int ret = hh * 3600 + mm * 60 + ss;
        return ret;
    }
    
    public String solution(String play_time, String adv_time, String[] logs) {
        String answer = ""; 
        
        long arr[] = new long[360001];
        
        for(int i=0;i<logs.length;i++){
            String s = logs[i];
            int sec1 = str_to_sec(s.substring(0, 8));
            int sec2 = str_to_sec(s.substring(9, 17));
            
            arr[sec1]++;
            arr[sec2]--;
        }
        
        // 원본 복구
        for(int i=0;i<360000;i++){
            arr[i+1] += arr[i]; 
        }
        
        // 누적합
        for(int i=0;i<360000;i++){
            arr[i+1] += arr[i]; 
        }
        
        int play_sec = str_to_sec(play_time);
        int adv_sec = str_to_sec(adv_time);
        
        long mx_sec = arr[adv_sec - 1];
        int ret_sec = 0;
        
        // 0 ~ play_sec - adv_sec
        for(int i=1;i<=play_sec - adv_sec;i++){
            long sec = arr[i + adv_sec-1] - arr[i-1]; // 누적합을 빼서 i ~ i+adv-1 까지의 광고 합 구하기
            if(mx_sec < sec){
                mx_sec = sec;
                ret_sec = i;
            }
        }
        String h = String.valueOf(ret_sec/3600);
        if(h.length() == 1) answer += "0";
        answer += h; answer += ":";
        ret_sec %= 3600;
        
        String m = String.valueOf(ret_sec/60);
        if(m.length() == 1) answer += "0";
        answer += m; answer += ":";
        ret_sec %= 60;
        
        String s = String.valueOf(ret_sec);
        if(s.length() == 1) answer += "0";
        answer += s;
     
        return answer;
    }
}