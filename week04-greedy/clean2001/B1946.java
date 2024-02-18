// 1946 신입 사원
import java.util.*;
import java.io.*;

class Main {
    static int T, N;
    static Node[] arr;

    static class Node implements Comparable<Node> {
        int a, b;

        Node(int a, int b){
            this.a = a;
            this.b = b;
        }

        public int compareTo(Node n) {
            return this.a - n.a;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(br.readLine());
        while(T-- > 0) {
            N = Integer.parseInt(br.readLine());

            arr = new Node[N];

            for(int i=0; i<N; ++i) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
                arr[i] = new Node(a, b);
            }

            Arrays.sort(arr); // 서류 점수에 대하여 오름차순 정렬

            int ans = 1; // 1번은 무조건 뽑을 수 있다.
            int min_val = arr[0].b; // b의 면접 등수보다 낮으면 뽑힐 수 없다.
            for(int i=1; i<N; ++i) {
                if(min_val < arr[i].b) continue; // 못뽑음

                min_val = arr[i].b; // 면접 등수 커트라인을 업데이트
                ans++;
            }

            System.out.println(ans);
        }
    }
}