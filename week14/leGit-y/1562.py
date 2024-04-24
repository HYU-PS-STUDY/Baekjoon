"""
10844. 쉬운 계단 수 문제와 유사
다른 점은 0~9까지의 모든 수를 써야한다는 조건이 추가된 부분
해당 부분을 체크하기 위한 bitmask 저장공간만 추가
dp[글자길이][마지막수][방문집합(bitmask)]
"""
import sys
input = sys.stdin.readline

MOD = 10**9
N = int(input())

"""
dp[수의길이][마지막수][방문집합]
1) 방문집합: 0~9까지의 수들 중 어느것 포함되는지 체크
    크기: 1<<10
2) 마지막수: 가능한 수들 (0~9)
    크기: 10
3) 수의길이: 입력값 (N)
"""
dp = [[[0 for _ in range(1<<10)] for _ in range(10)] for _ in range(N + 1)]

# 0으로 시작하든 수는 계단수 x, 따라서 범위 1부터 시작
for k in range(1, 10):
    dp[1][k][1 << k] = 1

for i in range(2,N+1):
    for j in range(10):
        for k in range(1<<10):
            bit = k | (1<<j)
            # 마지막 수가 0인 경우
            if j == 0:
                 # 그 이전수는 무조건 1이었어야
                dp[i][j][bit] += dp[i-1][1][k] % MOD
            # 마지막 수가 9인 경우
            elif j == 9:
                 # 그 이전수는 무조건 8이었어야
                dp[i][j][bit] += dp[i-1][8][k] % MOD
            else:
                dp[i][j][bit] += (dp[i-1][j-1][k] + dp[i-1][j+1][k]) % MOD


answer = 0
for j in range(10):
    answer += dp[N][j][(1 << 10) - 1]
    answer %= MOD

print(answer)
