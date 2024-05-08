import java.io.*;
import java.util.*;

// 상어 초등학교
class Main {
  static int N;
  static int num;
  static int[][] map;
  static int[] dy = {1, -1, 0, 0};
  static int[] dx = {0, 0, 1, -1};
  static int[][] likes;
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    num = N * N;
    map = new int[N+1][N+1];
    int[] turn = new int[num + 1];
    likes = new int[num + 1][4];
    for(int i=1; i<=num; ++i) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      turn[i] = Integer.parseInt(st.nextToken());
      for(int j=0; j<4; ++j) {
        likes[turn[i]][j] = Integer.parseInt(st.nextToken());
      }
    }

    for(int i=1; i<=num; ++i) {
      assign(turn[i]);
    }

    System.out.println(calPoint());

  }
  static void assign(int idx) {
    int y = 0, x = 0;
    int maxNumOfLike = -1;
    int maxNumOfEmpty = -1;
    // 가장 좋은 자리를 검사
    for(int i=1; i<=N; ++i) {
      for(int j=1; j<=N; ++j) {
        if(map[i][j] != 0) continue; // 이미 앉은 자리이다.

        int numOfLike = 0;
        int numOfEmpty = 0;
        for(int k=0; k<4; ++k) {
          int ny = i + dy[k];
          int nx = j + dx[k];

          if(!isSafe(ny, nx)) continue;

          if(map[ny][nx] == 0) {
            numOfEmpty++; continue;
          }

          for(int l=0; l<4; ++l) {
            if(map[ny][nx] == likes[idx][l]) {
              numOfLike++; break;
            }
          }
        }

        // 가장 좋은 자리인가?
        if(maxNumOfLike < numOfLike) {
          maxNumOfLike = numOfLike;
          maxNumOfEmpty = numOfEmpty;
          y = i; x = j;
        } else if(maxNumOfLike == numOfLike && maxNumOfEmpty < numOfEmpty) {
          maxNumOfEmpty = numOfEmpty;
          y = i; x = j;
        }
      }
    }

    map[y][x] = idx;
  }

  static boolean isSafe(int y, int x) {
    return y <= N && x <= N && x >= 1 && y >= 1;
  }


  static int calPoint() {
    // debug
//    for(int i=0; i<=N; ++i) {
//      for(int j=0; j<=N; ++j) {
//        System.out.print(map[i][j] + " ");
//      }
//      System.out.println();
//    }


    int ret = 0;
    for(int i=1; i<=N; ++i) {
      for(int j=1; j<=N; ++j) {
        int cnt = 0;
        for(int k=0; k<4; ++k) {
          int ny = i + dy[k];
          int nx = j + dx[k];

          if(!isSafe(ny, nx)) continue;

          for(int l=0; l<4; ++l) {
            if(likes[map[i][j]][l] == map[ny][nx]) {
              cnt++; break;
            }
          }
        }

        if(cnt == 1) ret += 1;
        else if(cnt == 2) ret += 10;
        else if(cnt == 3) ret += 100;
        else if(cnt == 4) ret += 1000;
      }
    }
    return ret;
  }
}