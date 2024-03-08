// 백준 1445. 일요일 아침의 데이트

import java.io.*;
import java.util.*;

class B1445 {
    static int N, M;
    static char[][] map;
    static boolean[][] visited;
    static final int INF = Integer.MAX_VALUE;
    static int[] dy = {1, -1, 0, 0};
    static int[] dx = {0, 0, -1, 1};
    static int ans1 = 0, ans2 = 0;

    static class Node implements Comparable<Node> {
        // garbage: g 위를 지난 횟수, adj: g 옆을 지난 횟수
        int garbage, adj;
        int y, x;

        Node (int garbage, int adj) {
            this.garbage = garbage;
            this.adj = adj;
        }

        Node (int y, int x, int garbage, int adj) {
            this.y = y;
            this.x = x;
            this.garbage = garbage;
            this.adj = adj;
        }

        // 정렬 기준 -> 오름차순 정렬시, garbage가 작은 것이 앞으로, garbage가 같다면 adj가 작은 것이 앞으로
        @Override
        public int compareTo(Node o) {
            if(o.garbage == this.garbage) return this.adj - o.adj;

            return this.garbage - o.garbage;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new char[N][M];
        visited = new boolean[N][M];

        int start_y = 0, start_x = 0;

        for(int i=0; i<N; ++i) {
            String line = br.readLine();
            for(int j=0; j<M; ++j) {
                char c = line.charAt(j);

                switch (c) {
                    case '.':
                        map[i][j] = c;
                        break;
                    case 'g':
                        map[i][j] = c;
                        break;
                    case 'S':
                        map[i][j] = '.';
                        start_y = i;
                        start_x = j;
                        break;
                    case 'F':
                        map[i][j] = 'F';
                        break;
                }
            }
        }

        make_adj(); // 'g'와 인접한 '.'을 'a'로 바꾸어 주는 함수
        bfs(start_y, start_x);

        System.out.println(ans1 + " " + ans2);
    }

    private static void make_adj() {
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                if(map[i][j] == 'g') {
                    for(int k=0; k<4; ++k){
                        int ny = i + dy[k], nx = j + dx[k];
                        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                        if(map[ny][nx] == '.') map[ny][nx] = 'a';
                    }
                }
            }
        }
    }

    private static void bfs(int start_y, int start_x) {

        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(start_y, start_x, 0, 0));
        visited[start_y][start_x] = true;

        while(!pq.isEmpty()) {
            Node cur = pq.poll();
            // cy, cx: 현재 위치, cg: 현재까지 쓰레기 위를 지난 수, ca: 현재까지 쓰레기 옆을 지난 수
            int cy = cur.y, cx = cur.x, cg = cur.garbage, ca = cur.adj;

            if(map[cy][cx] == 'F') {
                ans1 = cg;
                ans2 = ca;
                return;
            }

            for(int i=0; i<4; ++i) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(visited[ny][nx]) continue;

                int next_g, next_adj;
                if(map[ny][nx] == 'g') { // 현재 쓰레기 위이므로 next_g = cg+1;
                    next_g = cg+1; next_adj = ca;
                } else if (map[ny][nx] == 'a') { // 현재 쓰레기 옆이므로 next_adj = ca+1
                    next_g = cg; next_adj = ca+1;
                } else { // 현재 위치와 인접한 곳에 쓰레기가 없는 상태
                    next_g = cg; next_adj = ca;
                }

                visited[ny][nx] = true; // 큐에 넣을 때 방문처리
                pq.add(new Node(ny, nx, next_g, next_adj));
            }
        }

    }
}