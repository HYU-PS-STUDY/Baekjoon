// 3019. 테트리스
import java.io.*;
import java.util.*;

class Main {
    static int C, P;
    static int[] map;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        C = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        map = new int[C];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<C; ++i) {
            map[i] = Integer.parseInt(st.nextToken());
        }

        System.out.println(solve());

    }

    private static int solve() {
        int ret = 0;
        if(P == 1) { // 1x4
            // 1 - 1 -> 무조건 됨
            ret += C;

            // 1 - 2
            for(int i=0; i<=C-4; ++i) {
                ret += is_level(i, 4);
            }

        } else if(P == 2) { // 정사각형
            // 2 - 1
            for(int i=0; i<=C-2; ++i) {
                ret += is_level(i, 2);
            }
        } else if(P == 3) { // 오른쪽을 보고 있는 지그재그
            // 3 - 1
            for(int i=0; i<=C-3; ++i) {
                if(map[i] == map[i+1] && map[i] == map[i+2]-1) ret++;
            }

            // 3 - 2
            for(int i=0; i<=C-2; ++i) {
                if (map[i] == map[i + 1] + 1) ret++;
            }

        } else if(P == 4) {
            // 4 - 1
            for(int i=0; i<=C-3; ++i) {
                if(map[i+1] == map[i+2] && map[i]-1 == map[i+1]) ret++;
            }

            // 4 - 2
            for(int i=0; i<=C-2; ++i) {
                if (map[i] == map[i + 1] - 1) ret++;
            }

        } else if(P == 5) {
            // 5 - 1 ㅗ
            for(int i=0; i<=C-3; ++i) {
                ret += is_level(i, 3);
            }

            // 5 - 2 ㅏ
            for(int i=0; i<=C-2; ++i) {
                if(map[i] == map[i+1]-1) ret++;
            }

            // 5 - 3 ㅜ
            for(int i=0; i<=C-3; ++i) {
                if(map[i] == map[i+2] && map[i+1] == map[i]-1) ret++;
            }


            // 5 - 4 ㅓ
            for(int i=0; i<=C-2; ++i) {
                if(map[i] == map[i+1]+1) ret++;
            }


        } else if(P == 6) {
            // 6 - 1
            for(int i=0; i<=C-3; ++i) {
                ret += is_level(i, 3);
            }

            // 6 - 2
            for(int i=0; i<=C-2; ++i) {
                ret += is_level(i, 2);
            }

            // 6 - 3
            for(int i=0; i<=C-3; ++i) {
                if(map[i] == map[i+1]-1 && map[i+1] == map[i+2]) ret++;
            }

            // 6 - 4
            for(int i=0; i<=C-2; ++i) {
                if(map[i]-2 == map[i+1]) ret++;
            }


        } else if(P == 7) {
            // 7 - 1
            for(int i=0; i<=C-3; ++i) {
                ret += is_level(i, 3);
            }

            // 7 - 2
            for(int i=0; i<=C-2; ++i) {
                ret += is_level(i, 2);
            }

            // 6 - 3
            for(int i=0; i<=C-3; ++i) {
                if(map[i] == map[i+1] && map[i+1] == map[i+2]+1) ret++;
            }

            // 6 - 4
            for(int i=0; i<=C-2; ++i) {
                if(map[i]+2 == map[i+1]) ret++;
            }

        }

        return ret;
    }

    private static int is_level(int s, int c) { // i~i+c-1이 높이가 모두 같은지 체크
        int h = map[s];
        for(int i=s+1; i<s+c; ++i) {

            if (h != map[i]) return 0;
        }
        return 1;
    }

}