import java.io.*;
import java.util.*;
// 1406. 에디터
// 스택을 쓰지 않고, 직접 문자열을 고치는 식으로 구현하면
// substring()과 같은 O(N)인 메소드 때문에 시간초과가 발생합니다.
class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String input = br.readLine();

    int N = Integer.parseInt(br.readLine());
    Deque<String> st1 = new LinkedList<>();
    Deque<String> st2 = new LinkedList<>();

    for(int i=0; i<input.length(); ++i) {
      st1.addLast(Character.toString(input.charAt(i)));
    }
    for(int i=0; i<N; ++i) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      String cmd = st.nextToken();

      if(cmd.equals("P")) { // 추가하기 -> st1에 추가
        String ch = st.nextToken();
        st1.addLast(ch);
      } else if(cmd.equals("L")) { // 왼쪽으로 이동 -> s1에서 s2로 옮기기
        if(st1.isEmpty()) continue;
        st2.addLast(st1.pollLast());
      } else if(cmd.equals("B")) { // 삭제 -> s1하나 삭제
        if(st1.isEmpty()) continue;
        st1.removeLast();
      } else if(cmd.equals("D")) { // 오른쪽으로이동
        if(st2.isEmpty()) continue;
        st1.addLast(st2.pollLast());
      }

    }


    StringBuilder sb1 = new StringBuilder();
    while(!st1.isEmpty()) {
      sb1.append(st1.pollLast());
    }
    StringBuilder sb2 = new StringBuilder();
    while(!st2.isEmpty()) {
      sb2.append(st2.pollLast());
    }


    System.out.println(sb1.reverse().toString() + sb2.toString());

  }
}