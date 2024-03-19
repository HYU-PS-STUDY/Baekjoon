// 2206. 벽부수고 이동하기
import java.util.*;
import java.io.*;

class B2206 {
    static int N, M;
    static int[][] map;
    static boolean[][][] vis; // vis 배열이 3차원이어야함 -> y, x, wall(전에 벽 부순 여부)

    static int[] dy = {1, -1, 0, 0};
    static int[] dx = {0, 0, 1, -1};

    static int ans = -1;

    static class Node {
        int y, x, dist; // 위치와 이동거리
        boolean wall; // 이전에 벽을 부순 여부. true->부숨, false->안부숨

        Node(int y, int x, int dist, boolean wall) {
            this.y = y;
            this.x = x;
            this.dist = dist;
            this.wall = wall;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        vis = new boolean[N][M][2];

        for(int i=0; i<N; ++i) {
            String s = br.readLine();
            for(int j=0; j<M; ++j) {
                map[i][j] = s.charAt(j) - '0';
            }
        }

        bfs();
        System.out.println(ans);

    }


    private static void bfs() {
        vis[0][0][0] = true; // 위치: (0,0), 이전 벽 안부숨 -> 방문 처리

        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0, 0, 1, false)); // 순서대로 y, x, dist, wall

        while(!q.isEmpty()) {
            Node cur = q.poll();

            if(cur.y == N-1 && cur.x == M-1) { // 도착했다면
                ans = cur.dist;
                return;
            }

            for(int i=0; i<4; ++i) { // 상하좌우 이동
                int ny = cur.y+dy[i];
                int nx = cur.x+dx[i];

                if(!is_safe(ny, nx)) continue;

                if(map[ny][nx] == 0 && !cur.wall) { // 현재 위치가 벽이 아니면서 안부셨을 때
                    if(vis[ny][nx][0]) continue; // 이미 방문
                    vis[ny][nx][0] = true;

                    q.add(new Node(ny, nx, cur.dist+1, false));


                } else if(map[ny][nx] == 0 && cur.wall) { // 현재 위치가 벽이 아니면서 전에 이미 부셨을 때
                    if(vis[ny][nx][1]) continue; // 이미 방문
                    vis[ny][nx][1] = true;

                    q.add(new Node(ny, nx, cur.dist+1, true));

                } else if(map[ny][nx] == 1 && !cur.wall) { // 현재 위치가 벽이면서 안부셨을 때 => 부셔야함
                    if(vis[ny][nx][1]) continue; // 이미 방문
                    vis[ny][nx][1] = true;
                    q.add(new Node(ny, nx, cur.dist+1, true));
                }

                // 현재 위치가 벽이면 wall=true이면 벽을 부술 수 없으므로 갈수가 없다.

            }
        }
    }

    private static boolean is_safe(int y, int x) {
      return (y >= 0 && y < N && x >= 0 && x < M);
    }
}