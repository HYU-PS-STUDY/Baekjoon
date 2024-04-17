import java.io.*;
import java.util.*;
// 19637. IF문 좀 대신 써줘
class Main {
  static int[] power;
  static String[] name;
  static int N, M;
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    name = new String[N+1];
    power = new int[N+1];

    for(int i=0; i<N; ++i) {
      st = new StringTokenizer(br.readLine());
      name[i] = st.nextToken();
      power[i] = Integer.parseInt(st.nextToken());
    }

    for(int i=0; i<M; ++i) {
      int characterPower = Integer.parseInt(br.readLine());

      bw.write(findName(characterPower) + "\n");
    }

    bw.flush();
  }

  private static String findName(int characterPower) {
    int s = 0, e = N-1;
    while(s <= e) {
      int mid = (s + e) / 2;

      if(power[mid] < characterPower) s = mid+1;
      else e = mid-1;
    }

    return name[s];
  }
}