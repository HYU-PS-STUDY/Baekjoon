// 백준 14233 악덕 사장
import java.util.*;
import java.io.*;

class B14233 {
    static int n;
    static int[] deadline;
    static boolean can(int time) {
//        System.out.println(time);
        int total = 0;
        for(int i=0; i<n; ++i) {
            total += time;
            if(deadline[i] < total) return false;
        }

        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine().trim());
        deadline = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        for(int i=0; i<n; ++i) {
            deadline[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(deadline);

        int e = deadline[0], s = 1;

        int mid = (s+e)/2;

        while(true) {
            if(s > e && can(mid)) break;
            mid = (s+e) / 2;

            if(can(mid)) { // 시간을 더 늘려보기
                s = mid+1;
            } else {
                e = mid-1;
            }
        }

        bw.write(mid + "\n");
        bw.flush();
    }
}