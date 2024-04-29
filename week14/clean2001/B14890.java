import java.io.*;
import java.util.*;
// 경사로
class Main {
  static int N, L;
  static int[][] map;
  static boolean[][] isHeel;
  static class Node {
    int y, x;
    Node(int y, int x) {
      this.y = y;
      this.x = x;
    }
  }
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    L = Integer.parseInt(st.nextToken());

    map = new int[N][N];
    isHeel = new boolean[N][N];

    for(int i=0; i<N; ++i) {
      st = new StringTokenizer(br.readLine());
      for(int j=0; j<N; ++j) {
        map[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    int ans = 0;

    // 가로
    for(int i=0; i<N; ++i) {
      boolean[] rowHeel = new boolean[N];
      boolean flag = true;
      for(int j=0; j<N-1; ++j) {
        int diff = Math.abs(map[i][j] - map[i][j+1]);
        if(diff > 1) {
          flag = false; break; // 이 길은 안됨
        }

        if(diff == 1 && map[i][j] < map[i][j+1]) { // 왼쪽 검사
          int h = map[i][j];
          for(int d = 0; d<L; ++d) {
            int nx = j - d;
            if(nx < 0 || rowHeel[nx] || isHeel[i][nx] || h != map[i][nx]) {
              flag = false;
              break; // 이 길은 안됨
            }
          }

          if(flag) {
            for(int d = 0; d<L; ++d) {
              rowHeel[j-d] = true;
            }
          } else {
            break;
          }

        } else if(diff == 1 && map[i][j] > map[i][j+1]) { // 오른쪽 검사

          int h = map[i][j+1];
          for(int d=1; d<=L; ++d) {
            int nx = j + d;
            if(nx >= N || rowHeel[nx] || isHeel[i][nx] || h != map[i][nx]) {
              flag = false;
              break; // 이 길은 안됨
            }
          }

          if(flag) {
            for(int d=1; d<=L; ++d) {
              rowHeel[j+d] = true;
            }
          } else break;
        }
      }

      //
      if(flag) {
//        System.out.println("가로: " + i);
        ans++;
        for(int j=0; j<N; ++j) {
          if(rowHeel[j]) isHeel[i][j] = rowHeel[j];
        }
      }
    }


    // 세로
    isHeel = new boolean[N][N];
    for(int i=0; i<N; ++i) {
      boolean[] rowHeel = new boolean[N];
      boolean flag = true;
      for(int j=0; j<N-1; ++j) {
        int diff = Math.abs(map[j][i] - map[j+1][i]);
        if(diff > 1) {
          flag = false; break; // 이 길은 안됨
        }

        if(diff == 1 && map[j][i] < map[j+1][i]) { // 위쪽 검사
          int h = map[j][i];
          for(int d = 0; d<L; ++d) {
            int ny = j - d;
            if(ny < 0 || rowHeel[ny] || isHeel[ny][i] || h != map[ny][i]) {
              flag = false;
              break; // 이 길은 안됨
            }
          }

          if(flag) {
            for(int d = 0; d<L; ++d) {
              rowHeel[j-d] = true;
            }
          } else {
            break;
          }
        } else if(diff == 1 && map[j][i] > map[j+1][i]) { // 아래쪽 검사



          int h = map[j+1][i];
          for(int d=1; d<=L; ++d) {
            int ny = j + d;

            if(ny >= N || rowHeel[ny] || isHeel[ny][i] || h != map[ny][i]) {

              flag = false;
              break; // 이 길은 안됨
            }
          }

          if(flag) {
            for(int d=1; d<=L; ++d) {
              rowHeel[j+d] = true;
            }
          } else break;
        }
      }

      //
      if(flag) {
//        System.out.println("세로: " + i);
        ans++;
        for(int j=0; j<N; ++j) {
          if(rowHeel[j]) isHeel[j][i] = rowHeel[j];
        }
      }
    }

    System.out.println(ans);
  }
}