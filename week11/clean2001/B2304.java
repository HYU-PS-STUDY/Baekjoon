import java.io.*;
import java.util.*;
// 2304. 창고 다격현
class Main {
  static int N;
  static ArrayList<Node> list = new ArrayList<>();
  static int[] arr = new int[1001];
  static class Node {
    int x, y;

    Node(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());

    int max_x = 0, max_y = 0;
    for(int i=0; i<N; ++i) {
      StringTokenizer st = new StringTokenizer(br.readLine());

      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());

      arr[x] = y;

      if(max_y < y) { // 높이가 가장 높은 기둥의 위치를 찾아주기
        max_x = x;
        max_y = y;
      }

    }


    int area = max_y; // 가운데것을 더해주고 시작

    // 가장 높은 것을 기준으로 왼쪽
    Deque<Node> deque = new LinkedList<>(); // 스택처럼 사용
    for(int i=0; i<=max_x; ++i) {
      if(arr[i] == 0) continue;
      if(deque.isEmpty()) {
        deque.addFirst(new Node(i, arr[i]));
      } else if(deque.peekFirst().y <= arr[i]) { // 다음 기둥이 더 크거나 **같음**
        int dx = i - deque.peekFirst().x;
        int dy = deque.peekFirst().y;

        area += dy*dx;
        deque.addFirst(new Node(i, arr[i]));
      }
    }


    deque = new LinkedList<>(); // 스택처럼 사용
    for(int i=1000; i>=max_x; --i) {
      if(arr[i] == 0) continue;
      if(deque.isEmpty()) {
        deque.addFirst(new Node(i, arr[i]));
      } else if(deque.peekFirst().y <= arr[i]) { // 다음 기둥이 더 크거나 **같음**
        int dx = deque.peekFirst().x - i;
        int dy = deque.peekFirst().y;

        area += dy*dx;
        deque.addFirst(new Node(i, arr[i]));
      }
    }

    System.out.println(area);
  }
}