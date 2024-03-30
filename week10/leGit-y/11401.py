N,K=map(int, input().split())
MOD = 1000000007
top,bottom = 1, 1

for i in range(K):
    top *= N - i
    top %= MOD
for i in range(1, K + 1):
    bottom *= i
    bottom %= MOD

bottom = pow(bottom, -1, MOD)
print((top * bottom) % MOD)