from collections import deque
import sys

input = sys.stdin.readline


def bfs(i, j):
    global answer
    visited = [[0] * (M) for _ in range(N)]
    height = pool[i][j]
    min_height = 10
    q = deque([(i, j)])
    mini_pool = [(i, j)]
    visited[i][j] = 1

    while q:
        x, y = q.popleft()

        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]

            if nx in (-1, N) or ny in (-1, M):
                return 0, 0

            if height >= pool[nx][ny] and not visited[nx][ny]:
                q.append((nx, ny))
                mini_pool.append((nx, ny))
                visited[nx][ny] = 1
            elif height < pool[nx][ny]:
                min_height = min(min_height, pool[nx][ny])

    for ar in mini_pool:
        x, y = ar
        answer += (min_height - pool[x][y])
        pool[x][y] = min_height


N, M = map(int, input().split())
pool = [list(map(int, input().rstrip())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
answer = 0

for i in range(1, N - 1):
    for j in range(1, M - 1):
        bfs(i, j)

print(answer)