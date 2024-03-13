from collections import deque

def bfs(A, B):
    visited = [[0]*N for _ in range(N)]
    q = deque([A])

    while q:
        now = q.pop()
        for i in range(N):
            if graph[now][i] == 0 or visited[now][i]:
                continue
            if i == B:
                return 1

            q.append(i)
            visited[now][i] = 1
    return 0

def minus_one(n):
    n = int(n)
    return n-1


N = int(input())
M = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
plan = list(map(minus_one, input().split()))

# 이부분.... 이걸 어떻게 생각하지(이거때매 시간 상당히 날림)
if len(set(plan)) == 1:
    print('YES')
    exit()

for i in range(len(plan) - 1):
    A = plan[i]
    B = plan[i + 1]
    result = bfs(A,B)
    if result == 0:
        break

if result == 1:
    print('YES')
else:
    print('NO')