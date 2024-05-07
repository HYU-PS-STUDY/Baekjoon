import java.io.*;
import java.util.*;
// 21610. 마법사 상어와 비바라기
class Main {
  static int N, M;
  static int[] dy = {0, 0, -1, -1, -1, 0, 1, 1, 1};
  static int[] dx = {0, -1, -1, 0, 1, 1, 1, 0, -1};

  static int[] daey = {-1, -1, 1, 1};
  static int[] daex = {1, -1, -1, 1};
  static int[][] water;
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    water = new int[N+1][N+1];

    for(int i=0; i<N; ++i) {
      st = new StringTokenizer(br.readLine());
      for(int j=0; j<N; ++j) {
        water[i][j] = Integer.parseInt(st.nextToken());
      }
    }



    boolean[][] prevCloud= new boolean[N+1][N+1];
    prevCloud[N-1][0] = true;
    prevCloud[N-1][1] = true;
    prevCloud[N-2][0] = true;
    prevCloud[N-2][1] = true;
    for(int i=0; i<M; ++i) {
      st = new StringTokenizer(br.readLine());
      int dIdx = Integer.parseInt(st.nextToken());
      int s = Integer.parseInt(st.nextToken());
      boolean[][] cloud;
      // 1. 이동하기 -> 원형처리
      cloud = moveCloud(dIdx, s, prevCloud);
//      printWater();

      // 물 증가 시키기
      updateWater(cloud);


      // prevCloud 구름 배열 갱신하기
      prevCloud = updatePrevCloud(cloud);
    }

    System.out.println(calculateSum());

  }

  private static boolean[][] moveCloud(int dIdx, int s, boolean[][] prevCloud) {
    boolean[][] cloud = new boolean[N+1][N+1];
    for(int y=0; y<N; ++y) {
      for(int x=0; x<N; ++x) {
        if(prevCloud[y][x]) {
          int ny = (y + dy[dIdx] * s + 50 * N) % N;
          int nx = (x + dx[dIdx] * s + 50 * N) % N;

          cloud[ny][nx] = true;
          water[ny][nx]++;
        }
      }
    }

    return cloud;
  }

  private static void updateWater(boolean[][] cloud) {
    int[][] isIncrease = new int[N][N];
    for(int y=0; y<N; ++y) {
      for(int x=0; x<N; ++x) {
        if(!cloud[y][x]) continue;
        for(int k=0; k<4; ++k) {
          int ny = y + daey[k];
          int nx = x + daex[k];

          if(isSafe(ny, nx) && water[ny][nx] > 0) {
            isIncrease[y][x]++;
          }

        }
      }
    }

    for(int y=0; y<N; ++y) {
      for(int x=0; x<N; ++x) {
        water[y][x] += isIncrease[y][x];
      }
    }
  }

  private static boolean[][] updatePrevCloud(boolean[][] cloud) {
    boolean[][] ret = new boolean[N+1][N+1];
    for(int i=0; i<N; ++i) {
      for(int j=0; j<N; ++j) {
        if(water[i][j] >= 2 && !cloud[i][j]) {
          water[i][j] -= 2;
          ret[i][j] = true;
        }
      }
    }

    return ret;
  }

  private static boolean isSafe(int y, int x) {
    return y < N && y >= 0 && x < N && x >= 0;
  }

  private static int calculateSum() {
    int ret = 0;

    for(int i=0; i<N; ++i) {
      for(int j=0; j<N; ++j) {
        ret += water[i][j];
      }
    }

    return ret;
  }

  private static void printWater() {
    for(int i=0; i<N; ++i) {
      for(int j=0; j<N; ++j ){
        System.out.print(water[i][j] + " ");
      }

      System.out.println();
    }
    System.out.println();
  }
}