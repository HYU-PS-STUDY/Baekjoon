// B1781 컵라면
import java.io.*;
import java.util.*;

class Main {
    static int N;
    static ArrayList<Node> list;

    static class Node {
        long deadline;
        long cup; 
        /* 
         제가 스터디때 2^31 보다 작은 수이기에 long 써야한다고 잘못 설명하였는데,
         int 써도 풀릴 것 같습니다! 혼란을 드려 죄송해요ㅠ
         */


        Node(long deadline, long cup) {
            this.deadline = deadline;
            this.cup = cup;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        list = new ArrayList<>();

        for(int i=0; i<N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            list.add(new Node(d, c));
        }

        list.sort(new Comparator<Node>() {
            @Override
            public int compare(Node a, Node b) {
                return (int)(a.deadline - b.deadline);
            }
        }); // 데드라인에 대해서 오름차순 정렬

        PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node a, Node b) {
                return (int)(a.cup - b.cup);
            }
        }); // 컵라면이 적은 일이 위로 가도록

        for(int i=0; i<N; ++i) {
            long d = list.get(i).deadline;
            long c = list.get(i).cup;
            if(pq.size() < d) { // 일 할 수 있는 상황 -> 그냥 pq에 넣기
                pq.add(new Node(d, c));
            } else { // 뭘 빼야하는 상황
                if(pq.peek().cup < c) {
                    pq.remove();
                    pq.add(new Node(d, c));
                }
            }
        }

        long ans = 0;
        while(!pq.isEmpty()) {
            ans += pq.poll().cup;
        }

        System.out.println(ans);

    }
}