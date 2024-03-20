N = int(input())

max_w = 0
weight = []
for _ in range(N):
    w = int(input())
    weight.append(w)

weight.sort()

# 사용하는 로프의 개수에 따라 분리
for i in range(N,0,-1):
    tmp = weight[N-i] * i
    max_w = max(max_w,tmp)

print(max_w)

