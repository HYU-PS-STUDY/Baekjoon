import sys
input = sys.stdin.readline

N = int(input())
schedule = []
for _ in range(N):
    t,p = map(int, input().split())
    schedule.append((t,p))

dp = [0] * (N+1)
for i in range(1, N+1):
    dp[i] = max(dp[i-1], dp[i])
    t, p = schedule[i-1]
    t -= 1
    end = i + t
    if end > N:
        continue

    dp[end] = max(dp[i-1] + p, dp[end])

print(dp[N])

