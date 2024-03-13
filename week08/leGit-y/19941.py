def can_eat(cur):
    global cnt
    # 햄버거를 왼쪽부터 먹기위함
    for j in range(cur - K, cur + K + 1):
        if 0 <= j < N and arr[j] == "H":
            cnt += 1
            arr[j] = "X"
            return

N, K = map(int, input().split())
cnt = 0
arr = list(input())

for i in range(N):
    if arr[i] == 'P':
        can_eat(i)

print(cnt)