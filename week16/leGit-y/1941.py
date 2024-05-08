from collections import deque
from itertools import combinations
import sys
input = sys.stdin.readline

def more_than_four(pos):
    cnt = 0
    for x,y in pos:
        if student[x][y] == 'S':
            cnt += 1
            if cnt >= 4:
                return 1
    return 0

def is_adjacent(pos):
    visited = [[0] * N for _ in range(N)]
    i, j = pos[0]
    q = deque([(i,j)])
    visited[i][j] = 1
    cnt = 1

    while q:
        x, y = q.popleft()
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if nx in (-1,N) or ny in (-1,N):
                continue
            if visited[nx][ny]:
                continue

            if (nx,ny) in pos:
                q.append((nx,ny))
                visited[nx][ny] = 1
                cnt += 1
                if cnt >= 7:
                    return 1
    return 0


N = 5
student = [list(input().rstrip()) for _ in range(N)]
visited = [[0]*N for _ in range(N)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
pos = [(i,j) for i in range(N) for j in range(N)]
nCr = list(combinations(pos,7))

answer = 0
for c in nCr:
    check_1 = more_than_four(c)
    check_2 = is_adjacent(c)
    if check_1 and check_2:
        answer += 1

print(answer)
