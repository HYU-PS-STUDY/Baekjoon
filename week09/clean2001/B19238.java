import java.io.*;
import java.util.*;

// 19238. 스타트 택시
class Main {
    static int[][] map;
    /**
     * 사람이 서있는 곳을 표시한 맵으로, 입력이 들어온 순서를 저장했습니다.
     * 사람이 없는 곳 -> 0
     * i번째 사람이 있는 곳 -> i (i >= 1)
     */
    static int[][] person; 
    static int N, M, E; // N, M: 맵 크기, E: 초기 연료
    static ArrayList<Node> starts; // 사람이 서있는 위치를 저장한 리스트입니다.
    static ArrayList<Node> ends; // 도착 위치를 저장한 리스트입니다. ends에서 i번째 요소는 i번째 starts 요소의 도착위치
    static int cy, cx; // 택시으 현재 위치

    static int[] dy = {1, -1, 0, 0};
    static int[] dx = {0, 0, 1, -1};

    static class Node {
        int y, x;
        Node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static class Dist implements Comparable<Dist> {
        int y, x, d;

        Dist(int y, int x, int d) {
            this.y = y;
            this.x = x;
            this.d = d;
        }

        @Override
        public int compareTo(Dist o) {
            if(this.d == o.d && this.y == o.y) return this.x - o.x;
            else if(this.d == o.d) return this.y - o.y;

            return this.d - o.d;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        map = new int[N+1][N+1];
        person = new int[N+1][N+1];

        starts = new ArrayList<>();
        ends = new ArrayList<>();
        starts.add(new Node(0, 0)); // 인덱스를 1부터 시작하기 위해 넣은 의미없는 노드
        ends.add(new Node(0, 0)); // 인덱스를 1부터 시작하기 위해 넣은 의미없는 노드

        for(int i=1; i<=N; ++i) {
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=N; ++j) {
                map[i][j] = Integer.parseInt(st.nextToken());
                person[i][j] = 0; // 이건 아마 안해줘도 될 것입니다. (선언하면 다 0으로 초기화 돼있더라고요)
            }
        }

        // 택시의 출발 위치를 입력
        st = new StringTokenizer(br.readLine());
        cy = Integer.parseInt(st.nextToken());
        cx = Integer.parseInt(st.nextToken());

        // 사람 위치와 도착지 입력
        for(int i=1; i<=M; ++i) {
            st = new StringTokenizer(br.readLine());
            int py = Integer.parseInt(st.nextToken());
            int px = Integer.parseInt(st.nextToken());
            int ey = Integer.parseInt(st.nextToken());
            int ex = Integer.parseInt(st.nextToken());

            starts.add(new Node(py, px));
            ends.add(new Node(ey, ex));
            person[py][px] = i; // person 배열에는 사람이 서있는 위치의 사람의 인덱스(i)를 넣어줍니다.
        }

        System.out.println(solve());
    }

    private static int solve() {
        int i = 1;
        for(i=1; i<=M; ++i) {
            if(E < 0) break;

            /**
             * 가장 가까운 다음 손님 찾기
             * 리턴값이 Node로 되어있는데, 여기서는 위치를 리턴하는게 아니라,
             * y: 사람 인덱스, x: 그 사람까지의 최단거리
             * 를 담아서 리턴했습니다. (pair 값을 리턴해야하는데 새로운 클래스 만들기가 싫어서 재활용했습니다..ㅎㅎ)
            */
            Node tmp = find_next(); // 가까운 다음 손님 찾기
            int p_idx = tmp.y; // 사람 인덱스
            int dist = tmp.x; // 거기까지 걸린 거리
            if(p_idx==-1) return -1; // 인덱스가 음수이면 이제 태울 사람이 없음 -> 실패
            E -= dist; // 연료 차감(손님까지 가는 거리만큼)

            /**
             * 목적지로 갑니다.
             * 리턴값은 손님 위치 -> 목적지까지의 거리입니다.
             */
            int end_dist = go_to_end(p_idx);
            if(end_dist==-1) return -1; // 거리가 음수이면 목적지까지 갈수가 없는것 -> 실패
            E -= end_dist; // 연료 차감
            if(E < 0) break; // 연료 다씀 -> 실패
            E += 2*(end_dist); // 연료 충전

        }

        if(i == M+1 && E>=0) return E; // i가 M+1이면서 연료가 0이상이면 성공입니다.
        else return -1; // 실패
    }

    /**
     * 다음 태울 사람을 찾는 메소드
     */
    private static Node find_next() {
        boolean[][] vis = new boolean[N+1][N+1];
        /**
         * 예전 아기상어 같은 문제랑 비슷합니다.
         * 가장 가까운 손님을 찾되 그런 손님이 여러면이면 행값이 작은,
         * 그것도 여러면이면 열값이 작은 손님을 찾기 위해 그냥 큐가 아닌 pq를 선언해줍니다.
         */ 
        PriorityQueue<Dist> pq = new PriorityQueue<>(); 
        vis[cy][cx] = true;
        pq.add(new Dist(cy, cx, 0));
        int ret=0;
        int dist=0;
        while(!pq.isEmpty()) {
            Dist cur = pq.poll();

            if(person[cur.y][cur.x] > 0) {
                ret = person[cur.y][cur.x];
                dist = cur.d;
                person[cur.y][cur.x] = 0;
                cy = cur.y; cx = cur.x;
                return new Node(ret, dist); // 사람을 찾으면 바로 리턴해줍니다.
            }


            for(int i=0; i<4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if(!is_safe(ny, nx)) continue;
                if(map[ny][nx] == 1) continue;
                if(vis[ny][nx]) continue;

                pq.add(new Dist(ny, nx, cur.d+1));
                vis[ny][nx] = true;

            }
        }
        // while문을 나왔다는 것은 더이상 태울 수 있는 사람이 없다는 것입니다. -> 실패
        return new Node(-1, -1); 
    }

    /**
     * p_idx번째 손님의 목적지로 가는 메소드 
     */
    private static int go_to_end(int p_idx) {
        Node end = ends.get(p_idx);
        int ey = end.y;
        int ex = end.x;

        boolean[][] vis = new boolean[N+1][N+1];
        // 목적지로 가는건 그냥 큐 써도 되지 않을까 싶습니다.
        PriorityQueue<Dist> pq = new PriorityQueue<>();
        pq.add(new Dist(cy, cx, 0));
        vis[cy][cx] = true;


        while(!pq.isEmpty()) {
            Dist cur = pq.poll();

            if(cur.y == ey && cur.x == ex) {
                cy = cur.y; cx = cur.x;
                return cur.d;
            }

            for(int i=0; i<4; ++i) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];

                if(!is_safe(ny, nx)) continue;
                if(map[ny][nx] == 1) continue;
                if(vis[ny][nx]) continue;

                pq.add(new Dist(ny, nx, cur.d+1));
                vis[ny][nx] = true;
            }
        }

        return -1; // ㅓ못감
    }

    private static boolean is_safe(int y, int x) {
        return y >= 1 && y <= N && x >= 1 && x <= N;
    }
}