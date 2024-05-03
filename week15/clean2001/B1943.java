import java.io.*;
import java.util.*;
// 1943. 동전 분배
class Main {
  static int N;
  static int[][] coin;
  static int[][] dp;
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = 3;
    while(T-- >0) {

      N = Integer.parseInt(br.readLine());
      int sum = 0;
      int ans = 0;
      dp = new int[N][100001];
      coin = new int[N][2];
      for(int i=0; i<N; ++i) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        coin[i][0] = Integer.parseInt(st.nextToken());
        coin[i][1] = Integer.parseInt(st.nextToken());

        sum += coin[i][0] * coin[i][1];

        for(int j=0; j<coin[i][1]; ++j) {
          dp[i][j*coin[i][0]] = 1;
        }
      }



      if(sum % 2 == 0) {
        for(int i=0; i<N; ++i) {
          for(int j=0; j<100001; ++j) dp[i][j] = -1;
        }
        ans = makeDp(0, sum/2);
      }

      System.out.println(ans);
    }

  }

  static int makeDp(int idx, int price) {
    if(price < 0) return 0;
    if(idx == N) return price == 0 ? 1 : 0;

    if(dp[idx][price] != -1) return dp[idx][price];
    dp[idx][price] = 0;
    for(int i=0; i<=coin[idx][1]; i++) { // 코인 개수만큼 돌기
      // idx번째 코인을 하나 추가로 쓰고(price - coin[idx][0] * i), 그 남은 금액을 idx+1번째 코인들로 만들 수 있는 확인 
      dp[idx][price] = Math.max(dp[idx][price], makeDp(idx+1, price - coin[idx][0] * i));
    }

    return dp[idx][price];
  }
}