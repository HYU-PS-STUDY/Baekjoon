from collections import deque
import sys
input = sys.stdin.readline

def draw_path(sx,sy,ex,ey,visited,path):
    while True:
        visited[sx][sy] = True
        if sx == ex and sy == ey:
            break
        sx,sy = path[sx][sy]


def get_dist(a1x,a1y,a2x,a2y,b1x,b1y,b2x,b2y):
    visited = [[0] * (M + 1) for _ in range(N + 1)]
    path = [[(0, 0) for _ in range(M + 1)] for _ in range(N + 1)]

    visited[b1x][b1y] = 1
    visited[b2x][b2y] = 1
    dist_1 = bfs(a1x,a1y,a2x,a2y,visited,path)
    # 먼저 잇고
    visited = [[0] * (M + 1) for _ in range(N + 1)]
    draw_path(a2x,a2y,a1x,a1y,visited,path)

    # 거리 구하기
    dist_2 = bfs(b1x,b1y,b2x,b2y,visited,path)

    return dist_1 + dist_2

def bfs(sx,sy,ex,ey,visited,path):
    q = deque([(sx,sy)])
    visited[sx][sy] = 1

    while q:
        x,y = q.popleft()
        if x == ex and y == ey:
            return visited[ex][ey] - 1
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]

            if nx in (-1, N+1) or ny in (-1, M+1):
                continue
            if visited[nx][ny]:
                continue

            q.append((nx,ny))
            visited[nx][ny] = visited[x][y] + 1
            path[nx][ny] = (x,y)

    return INF


INF = 1e9
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

N, M = map(int, input().split())
a1x, a1y = map(int, input().split())
a2x, a2y = map(int, input().split())
b1x, b1y = map(int, input().split())
b2x, b2y = map(int, input().split())

result_1 = get_dist(a1x,a1y,a2x,a2y,b1x,b1y,b2x,b2y)
result_2 = get_dist(b1x,b1y,b2x,b2y,a1x,a1y,a2x,a2y)

answer = min(result_1,result_2)
if answer >= 1e9:
    print("IMPOSSIBLE")
else:
    print(answer)
