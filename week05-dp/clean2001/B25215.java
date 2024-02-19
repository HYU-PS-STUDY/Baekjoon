// 백준 25215. 타이핑 
import java.io.*;
import java.util.*;

class B25215 {
    static String s;
    static int dp[][];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        s = br.readLine().trim();
        dp = new int[2][s.length()+1];

        s = " " + s; // 인덱스를 맞춰주기 위해 (문자열의 시작을 1부터)

        dp[0][0] = 0; // 0행 -> 마름모 비활성화
        dp[1][0] = 1; // 1행 -> 마름모 활성화

        for(int i=1; i<s.length(); ++i) {
            if(s.charAt(i) >= 'a' && s.charAt(i) <= 'z') { // 소문자이면
                dp[0][i] = Math.min(dp[0][i-1] + 1, dp[1][i-1]+2);
                dp[1][i] = dp[1][i-1] + 2; // 활성화를 유지
            } else { // 대문자이면
                dp[1][i] = Math.min(dp[1][i-1] + 1, dp[0][i-1]+2);
                dp[0][i] = dp[0][i-1] + 2; // 비활유지
            }
        }

        int ans = Math.min(dp[0][s.length()-1], dp[1][s.length()-1]);

        System.out.println(ans);
    }

}