import java.util.*;
import java.io.*;

class B1946 {
    static int T, N;
    static Node[] arr;
    static class Node implements Comparable<Node>{
        int a, b;

        Node (int a, int b) {
            this.a = a; this.b = b;
        }

        public int compareTo(Node n) {
            return this.a - n.a;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());
        for(int i=0; i<T; ++i) {
            int ans = 1;
            N = Integer.parseInt(br.readLine());
            arr = new Node[N];
            for(int j=0; j<N; ++j) {
                StringTokenizer st = new StringTokenizer(br.readLine());

                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                arr[j] = new Node(a, b);
            }

            Arrays.sort(arr);

//            for(int j=0; j<N; ++j) System.out.println(arr[j].a);
            int s = arr[0].b;
            for(int j=1; j<N; ++j) {
                if(arr[j].b < s) {
                    s = arr[j].b;
                    ++ans;
                }
            }

            System.out.println(ans);
        }
    }
}