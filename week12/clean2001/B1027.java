import java.io.*;
import java.util.*;
// 1027. 고층 건물
class Main {
  static int N;
  static int[] arr;

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    arr = new int[N];

    StringTokenizer st = new StringTokenizer(br.readLine());
    for(int i=0; i<N; ++i) {
      arr[i] = Integer.parseInt(st.nextToken());
    }

    int ans = 0;
    for(int b=0; b<N; ++b) { // b번째 건물을 기준으로 양옆에 건물 몇개 보이는지 확인
      // 뒤쪽 확인
      int cnt1 = 0;
      for(int i=b-1; i>=0; i--) { // i와 b 건물 사이
        // 직선을 구하기
        double t = tan(i, b, arr[i], arr[b]);
        double k = y_meet(i, arr[i], t);

        // i~b 사이에 건물들이 닿는지를 확인
        boolean flag = false;
        for(int j=i+1; j<b; ++j) {
          double y_hat = t * (double)j + k; //
          if(y_hat <= (double) arr[j]) {
            flag = true;
            break;
          }
        }

        if(!flag) { // 안 닿았음 -> 됨
          cnt1++;
        }

      }

      // 앞쪽 확인
      int cnt2 = 0;
      for(int i=b+1; i<N; i++) { // b와 i 사이
        // 직선을 구하기
        double t = tan(i, b, arr[i], arr[b]);
        double k = y_meet(i, arr[i], t);

        // b~i 사이에 건물들이 닿는지를 확인
        boolean flag = false;
        for(int j=b+1; j<i; ++j) {
          double y_hat = t * (double)j + k; //
          if(y_hat <= (double) arr[j]) {
            flag = true;
            break;
          }
        }

        if(!flag) { // 안 닿았음 -> 됨
          cnt2++;
        }

      }


      if(ans < cnt1+cnt2) {
        ans = cnt1+cnt2;

      }
    }

    System.out.println(ans);

  }

  public static double tan(int x1, int x2, int y1, int y2) {
    if(x1 == x2) return 0; // 있을 수 없는 경우

    return (((double)y2-(double)y1) / ((double)x2-(double)x1));
  }

  public static double y_meet(int x1, int y1, double t) {
    return (double)y1 - t * (double)x1;
  }
}