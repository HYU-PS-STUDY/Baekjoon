// 14889. 스타트와 링크
import java.util.*;
import java.io.*;

class B14889 {
    static int N;
    static int ans;
    static int[][] map;
    static boolean[] visited;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        visited = new boolean[N+1];
        map = new int[N+1][N+1];

        for(int i=1; i<=N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=1; j<=N; ++j) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        ans = Integer.MAX_VALUE;
        dfs(0, 1);

        System.out.println(ans);

    }

    private static void dfs(int cnt, int idx) { // 브루트포스 -> 팀을 나누는 모든 경우를 고려하면된다.

        if(cnt == (N/2)) { // 팀 완성
            int score1=0, score2=0;
            ArrayList<Integer> t1 = new ArrayList<>();
            ArrayList<Integer> t2 = new ArrayList<>();
            for(int i=1; i<=N; ++i) {
                if(visited[i]) {
                    t1.add(i); // 방문을 한 팀은 1번팀
                } else {
                    t2.add(i); // 아직 방문하지 않은 팀은 2번팀
                }
            }

            for(int a : t1) { // 1번 팀 점수 구하기
                for(int b : t1) {
                    if(a == b) continue;
                    score1 += map[a][b];
                }
            }

            for(int a : t2) { // 2번 팀 점수 구하기
                for(int b : t2) {
                    if(a == b) continue;
                    score2 += map[a][b];
                }
            }

            ans = Math.min(ans, Math.abs(score1 - score2));
            return;
        }

        if(idx > N) return;

        for(int i=idx; i<=N; ++i) {
            visited[i] = true;
            dfs(cnt+1, i+1);
            visited[i] = false;
        }

    }
}