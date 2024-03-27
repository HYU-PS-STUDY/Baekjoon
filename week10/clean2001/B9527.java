// 9527. 1의 개수 세기

import static java.lang.Math.log;

import java.io.*;
import java.util.*;

class Main {
    static long A, B;
    static long[] dp = new long[57];
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Long.parseLong(st.nextToken());
        B = Long.parseLong(st.nextToken());

        dp[0] = 1; // (2^0 = 1 에서의 1의 개수) == 1
        // dp 배열을 만들어 줍니다.
        // dp[n]은 1~2^n-1까지의 1의 개수의 총합을 의미합니다. (ex. n==3이면 1~7의 1개수 총합)
        for(int i=1; i<56; ++i) {
            dp[i] = 2*dp[i-1] + (1L<<i);
        }

        System.out.println(solve(B) - solve(A-1));
    }

    static long solve(long N) {
        long ret = N & 1;

        // N보다 같거나 작으면서 가장 가까운 2^n인 수가 있을 때, n이 뭔지 구하기 => 즉 N이 이진수 몇개로 이뤄져있는지
        int n = (int)(log(N) / log(2));
        for(int i=n; i>0; --i) {
            if((N & (1L<<i)) == 0) continue; // 해당 자리가 0임

            ret += (dp[i-1] + (N - (1L << i) + 1L));
            // dp[i-1]: 1100이라고 치면, 1000이 되기 까지 000~111이 있었음. 그것에 대한 누적합을 더해준것. 즉 예시에서는 dp[3]
            // N - (1<<i) + 1: 1100이라고 치면, 뒤에 100이 000~100까지 증가하는 동안 맨 앞 1은 계속 있었음 따라서 4(100) + 1을 더해준 것

            N -= (1L << i);
        }

        return ret;
    }

}