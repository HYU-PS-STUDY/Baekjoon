// 백준 5972. 택배 배송
import java.io.*;
import java.util.*;

class B5972 {
    static int N, M;
    static ArrayList<ArrayList<Node>> adj = new ArrayList<>();
    static int[] visited;

    static final int INF = Integer.MAX_VALUE;
    static class Node implements Comparable<Node> {
        int node;
        int weight;

        Node(int node, int weight) {
            this.node = node;
            this.weight = weight;
        }

        public int compareTo(Node o) {
            return this.weight - o.weight;
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i=0; i<=N; ++i) {
            adj.add(new ArrayList<>());
        }

        visited = new int[N+1];
        for(int i=0; i<=N; ++i) {
            visited[i] = INF;
        }

        for(int i=0; i<M; ++i) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            adj.get(a).add(new Node(b, c));
            adj.get(b).add(new Node(a, c));
        }

        dijkstra();

        bw.write(visited[N] + "\n");
        bw.flush();
        br.close(); bw.close();
    }

    private static void dijkstra() {
        visited[1] = 0;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(1, 0));

        while(!pq.isEmpty()) {
            Node cur = pq.poll();

            if(visited[cur.node] < cur.weight) continue;

            for(Node next : adj.get(cur.node)) {
                if(visited[next.node] > cur.weight + next.weight) {
                    visited[next.node] = cur.weight + next.weight;
                    pq.add(new Node(next.node, visited[next.node]));
                }
            }
        }
    }
}