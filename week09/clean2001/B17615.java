import java.io.*;
import java.util.*;

// 17615. 볼 모으기
class Main {
    static int N;
    static String S;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        S = br.readLine();

        // 1. 빨강을 왼쪽으로 이동, 2. 빨강을 오른쪽으로 이동, 3. 파랑을 왼쪽으로 이동, 4. 파랑을 오른쪽으로 이동
        // 이 4가지 경우를 모두 직접 구하여, 최소값을 찾았습니다.
        // 아래 4개의 변수는 각각의 상황에 대한 점프 횟수입니다.
        int n1 = 0, n2 = 0, n3 = 0, n4 = 0;

        // flag는 현재 옮겨주고 있는 구슬과 다른 색의 구슬이 등장했는지의 여부입니다.
        // 현재 옮기고 있는 구슬이 R이라면, 한번이라도 B를 만나면 그 R은 B를 뛰어넘어주어야 하므로 이를 boolean으로 표시했습니다.
        boolean flag;

        // R, 왼 -> 빨간 구슬을 왼쪽으로 옮겨주는 경우
        if(S.charAt(0) == 'R') flag = false; // R
        else flag = true; // B
        for(int i=1; i<N; ++i) {
            if (S.charAt(i) == 'R' && flag) { // 구슬이 R인데, 뛰어넘을 B가 있는 상황 -> 점프 횟수 증가
                n1++;
            } else if(S.charAt(i) == 'B' && !flag) { // 처음으로 B를 만난 상황 -> flag를 켜준다.
                flag = true;
            }

            // 현재 구슬이 B이거나, 아직 B를 만난 적이 없다면 아무것도 안해도 됩니다.
        }

        // R, 오 -> 빨간 구슬을 오른쪽으로 옮겨주는 경우
        if(S.charAt(N-1) == 'R') flag = false; // R
        else flag = true; // B
        for(int i=N-2; i>=0; --i) {
            if (S.charAt(i) == 'R' && flag) {
                n2++;
            } else if(S.charAt(i) == 'B' && !flag) {
                flag = true;
            }
        }

        // B, 왼
        if(S.charAt(0) == 'B') flag = false; // B
        else flag = true; // R
        for(int i=1; i<N; ++i) {
            if (S.charAt(i) == 'B' && flag) {
                n3++;
            } else if(S.charAt(i) == 'R' && !flag) {
                flag = true;
            }
        }

        // B, 오
        if(S.charAt(N-1) == 'B') flag = false; // B
        else flag = true; // R
        for(int i=N-2; i>=0; --i) {
            if (S.charAt(i) == 'B' && flag) {
                n4++;
            } else if(S.charAt(i) == 'R' && !flag) {
                flag = true;
            }
        }

        int ans = Math.min(n1, n2);
        ans = Math.min(ans, n3);
        ans = Math.min(ans, n4);

        System.out.println(ans);

    }
}