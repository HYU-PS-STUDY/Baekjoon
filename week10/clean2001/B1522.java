// 1522. 문자열 교환
import java.io.*;
import java.util.*;

class Main {
    static String line;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        line = br.readLine();

        // a의 개수를 세어준다.
        int cnt = 0;
        for(int i=0; i<line.length(); ++i) {
            if(line.charAt(i) == 'a') cnt++;
        }

        // 슬라이딩 윈도우
        int min_b_cnt = 10001;
        for(int i=0; i<line.length(); ++i) {
            int b_cnt = 0;
            int s = i;
            int e = i+cnt;
            for(int j=s; j<e; ++j) {
                int idx = j % line.length();

                if(line.charAt(idx) == 'b') b_cnt++;
            }

            min_b_cnt = Math.min(min_b_cnt, b_cnt);
        }

        System.out.println(min_b_cnt);
    }
}