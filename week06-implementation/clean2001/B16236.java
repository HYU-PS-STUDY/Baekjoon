import java.io.*;
import java.util.*;

class Main {
    static int N;
    static int[][] map; // 물고기, 벽이 저장돼있는 맵
    static int shark = 2; // 현재 상어의 크기
    static int remain = 2; // 크기가 커지기 위해 앞으로 먹어야하는 물고기 수
    static int cury, curx; // 현재 상어 위치
    
    static class Node {
        int y, x;
        int dist;

        Node(int y, int x, int dist) {
            this.y = y;
            this.x = x;
            this.dist = dist;
        }
    }

    static int[] dy = {-1, 0, 0, 1};
    static int[] dx = {0, -1, 1, 0};
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        map = new int[N][N];

        for(int i=0; i<N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<N; ++j) {
                map[i][j] = Integer.parseInt(st.nextToken());

                if(map[i][j] == 9) { // 아기 상어
                    cury = i;
                    curx = j; // 현재 아기상어 위치 저장
                    map[i][j] = 0; // 아기상어의 위치는 지나갈 수 있는 곳이므로 0으로 바꿔준다.
                }
            }
        }

        int ans = 0;
        while(true) {
            int ret = bfs(cury, curx); // 현재 위치에서 bfs 시작. 리턴값은 버틴 시간

            if(ret == -1) break; // 더이상 먹을 수 있는 물고기 없음 -> 종료

            ans += ret; // 버틴 시간 더하기
            remain--; // 먹은 물고기 차감
            if(remain == 0) { // remain  == 0이면 사이즈(shark)가 커지고, remain이 shark로 리셋된다.
                shark++;
                remain = shark;
            }

        }

        System.out.println(ans);
    }

	// 현재 아기상어 위치에서 bfs를 하여 가장 가까운 먹을 수 있는 물고기 위치를 탐색하고,
    // 가장 가까우면서 먹을 수 있는 물고기를 만나면 버틴 시간을 반환하며 함수를 빠져나옵니다.
    private static int bfs(int cy, int cx) {
        PriorityQueue<Node> q = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
            	// 거리, 높이가 같으면 x값이 작은게 pq의 위로 가도록 함
                if(o1.dist == o2.dist && o1.y == o2.y) return o1.x - o2.x;
                else if(o1.dist == o2.dist) return o1.y - o2.y; // 거리만 같다면 y값이 작은게 pq의 위로 가도록 함

                return o1.dist - o2.dist; // x, y 가 다르면 가장 거리가 짧은게 pq의 위로 가도록함
            }
        });
        // priority queue를 만드는 이유는 문제에
        // 1. 가장 가까운 물고기부터 먹는다.
        // 2. 가까운게 여러개라면 가장 위에 있는 걸 먹는다.
        // 3. 위에 있는게 여러개이면 가장 왼쪽에 있는 걸 먹는다. 라는 조건이 있기 때문입니다.

        q.add(new Node(cy, cx, 0 )); // 3번째 인자: 아기 상어 시작 위치부터 현재 좌표까지의 거리

        boolean[][] visited = new boolean[N][N];
        visited[cy][cx] = true;

        int cnt;

        while(!q.isEmpty()) {
            Node cur = q.poll(); // pq에서 Comparator를 정의했으므로, 가장 가까운, 가장 위에 있는, 가장 왼쪽에 있는 물고기 순으로 나오는 것이 보장된다.

			
            // map의 값이 0이 아니면서 상어의 크기보다 작을 때 -> 물고기를 먹는다.
            if(map[cur.y][cur.x] > 0 && map[cur.y][cur.x] < shark) {
                map[cur.y][cur.x] = 0;
                cury = cur.y;
                curx = cur.x;
                cnt = cur.dist;

                return cnt;
            }

            for(int i=0; i<4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if(ny < 0 || nx <0 || ny >= N || nx >= N) continue;
                if(map[ny][nx] > shark) continue;
                if(visited[ny][nx]) continue;

                visited[ny][nx] = true;
                q.add(new Node(ny, nx, cur.dist + 1));
            }
        }
        return -1;
    }
}