// 백준 9460 메탈
import java.util.*;
import java.io.*;

class B9460 {
    static int T, n, k;
    static Node[] dots;

    static class Node implements Comparable<Node> {
        public int x, y;

        Node(int x, int y) {
            this.x = x;
            this.y = y;
        }


        @Override
        public int compareTo(Node o) {
            return this.x - o.x;
        }
    }

    static boolean can(double cost) {
        int minh=100000000, maxh=-100000000;
        int cnt = 1;
        for(int i=0; i<n; ++i) {
            int y = dots[i].y;

            minh = Math.min(minh, y);
            maxh = Math.max(maxh, y);
            double new_cost = ((double)maxh - (double)minh) / 2;

            if(new_cost > cost) {
                cnt++; // 새 터널 설치
                minh = y; maxh = y; // 현재 y부터 다시시작
            }
        }

        if(cnt > k) return false;
        return true;

    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());

        for(int i=0; i<T; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            dots = new Node[n];

            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++) {
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                dots[j] = new Node(x, y);
            }

            Arrays.sort(dots); // x 좌표로 정렬

            double s = 0.0, e = 100000001.0; // cost의 범위
            double mid = 0, ans = 100000001.0; //
            while(e - s > 0.001) {
                mid = (s+e)/2;

                if(can(mid)) {
                    e = mid;
                    ans = Math.min(mid, ans);
                } else {
                    s = mid;
                }
            }

//            ans =
            System.out.printf("%.1f\n", ans);
        }
    }
}