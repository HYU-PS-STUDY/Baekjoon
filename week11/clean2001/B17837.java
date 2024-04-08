import java.io.*;
import java.util.*;

class Main {
  static int N, K;
  static LinkedList<Node>[][] map;
  static int[][] color;
  static ArrayList<Node> list = new ArrayList<>();

  static class Node {
    int num;
    int direction;
    int y, x;

    Node(int num, int direction, int y, int x) {
      this.num = num;
      this.direction = direction;
      this.y = y;
      this.x = x;
    }
  }

  static int[] dy = {0, 0, -1, 1};
  static int[] dx = {1, -1, 0, 0};

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    map = new LinkedList[N+1][N+1];
    for(int i=0; i<N+1; ++i) {
      for(int j=0; j<N+1; ++j) {
        map[i][j] = new LinkedList<Node>();
      }
    }
    color = new int[N+1][N+1];


    // 색 입력 받기
    for(int i=1; i<=N; ++i) {
      st = new StringTokenizer(br.readLine());
      for(int j=1; j<=N; ++j) {
        color[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    list.add(null);
    for(int i=1; i<=K; ++i) {
      st = new StringTokenizer(br.readLine());
      int r = Integer.parseInt(st.nextToken());
      int c = Integer.parseInt(st.nextToken());
      int d = Integer.parseInt(st.nextToken());

      list.add(new Node(i, d-1, r ,c));
      map[r][c].add(list.get(i)); // 말을 체스판에 놓기
    }


    // 게임 시작
    int i;
    boolean flag = false;
    for(i=1; i<=1000; ++i) {
      for(int j=1; j<=K; ++j) { // 말 하나씩 이동
        Node n = list.get(j);
        int ny = n.y + dy[n.direction];
        int nx = n.x + dx[n.direction];

        if(ny > N || nx > N || ny < 1 || nx < 1) { // 밖으로 나감 -> 방향 바꾸고 한칸 가기 (파랑이거나 바깥이면 안가기)
          if(n.direction==0) n.direction =1;
          else if(n.direction==1) n.direction = 0;
          else if(n.direction==2) n.direction = 3;
          else if(n.direction==3) n.direction = 2;
          if(move(j)) {
            flag = true;
            break;
          }
        } else if(color[ny][nx] == 0) { // 그냥 가면 됨
          if(move(j)) {
            flag = true;
            break;
          }
        } else if(color[ny][nx] == 1) { // 빨강
          if(move(j)) {
            flag = true;
            break;
          }
        } else if(color[ny][nx] == 2) { // 파랑
          if(n.direction==0) n.direction =1;
          else if(n.direction==1) n.direction = 0;
          else if(n.direction==2) n.direction = 3;
          else if(n.direction==3) n.direction = 2;
          if(move(j)) {
            flag = true;
            break;
          }
        }
      }

      if(flag) break;

    }

    if (i >= 1001) {
      System.out.println(-1);
    } else {
      System.out.println(i);
    }

  }

  static boolean move(int node) { // 노드 번호
    Node n = list.get(node);
    // 새로 가야하는 곳
    int ny = n.y + dy[n.direction];
    int nx = n.x + dx[n.direction];

    int cur_y = n.y;
    int cur_x = n.x;


    if (ny > N || nx > N || ny < 1 || nx < 1) {
      // 밖이거나 파랑이면 가지 않는다.
      return map[cur_y][cur_x].size() >= 4;
    } else if(color[ny][nx] == 2) { // 4개인지만 체크
      return map[ny][nx].size() >= 4;
    }



    // 내가 덱에서 몇번째인지 찾기
    int idx = map[cur_y][cur_x].indexOf(n);

    // 나와 내 위에 있는거 옮겨주기
    List<Node> moved = new ArrayList<>();
    if(color[ny][nx] == 0) {
      for (int i = idx; i < map[cur_y][cur_x].size(); ++i) {
        Node cur = map[cur_y][cur_x].get(i);
        moved.add(cur);
        map[ny][nx].addLast(cur); // 위에 쌓기
        cur.y = ny;
        cur.x = nx;
      }
    } else { // 빨강

      for (int i = map[cur_y][cur_x].size()-1; i >= idx ; --i) {
        Node cur = map[cur_y][cur_x].get(i);
        moved.add(cur);
        map[ny][nx].addLast(cur); // 위에 쌓기
        cur.y = ny;
        cur.x = nx;
      }

    }

    // 옮겨졌던 것들을 제거
    for(Node m : moved) map[cur_y][cur_x].remove(m);


    if (map[ny][nx].size() >= 4) {
      return true;
    }

    return false;
  }
}