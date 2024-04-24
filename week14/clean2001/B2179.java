import java.io.*;
import java.util.*;

class Main {
  static int N;
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    String[] arr = new String[N];
    String[] original = new String[N];
    Map<String,Integer> map = new HashMap<>();
    for(int i=0; i<N; ++i) {
      arr[i] = br.readLine();
      original[i] = arr[i];
      map.put(arr[i], i);
    }

    Arrays.sort(arr);
    String prefix = "";
    int idx1=Integer.MAX_VALUE, idx2=Integer.MAX_VALUE;
    for(int i=0; i<N-1; ++i) {
      StringBuilder sb = new StringBuilder();
      int len = Math.min(arr[i].length(), arr[i+1].length());
      for(int j=0; j<len; ++j) {
        if(arr[i].charAt(j) == arr[i+1].charAt(j)) sb.append(arr[i].charAt(j));
        else break;
      }

      String curPrefix = sb.toString();
      if(curPrefix.length() > prefix.length()) {
        prefix = curPrefix;
        idx1 = map.get(arr[i]);
        idx2 = map.get(arr[i+1]);
      } else if(curPrefix.length() == prefix.length() && !prefix.equals(curPrefix)) {
        // 길이가 같으면 원래 인덱스가 더 작은 것을 선택
        int tempIdx1 = map.get(arr[i]);
        int tempIdx2 = map.get(arr[i+1]);

        int[] tempArr = {idx1, idx2, tempIdx1, tempIdx2};
        Arrays.sort(tempArr);


        if(tempArr[0] == tempIdx1 || tempArr[0] == tempIdx2) {
          idx1 = tempIdx1;
          idx2 = tempIdx2;
          prefix = curPrefix;
        }
      }
    }

    int cnt = 0;
//    System.out.println(prefix);
    for(int i=0; i<N; ++i) {
      if(original[i].length() < prefix.length()) continue;
      if(prefix.equals(original[i].substring(0, prefix.length()))) {
        cnt++;
        System.out.println(original[i]);
      }

      if(cnt == 2) break;
    }
  }
}