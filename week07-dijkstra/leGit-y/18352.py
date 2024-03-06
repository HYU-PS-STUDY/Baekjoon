import heapq
import sys
input = sys.stdin.readline

def dijkstra(start):
    q = []
    heapq.heappush(q,(0,start))
    distance[start] = 0

    while q:
        dist, node = heapq.heappop(q)
        if distance[node] < dist:
            continue
        for n in city[node]:
            cost = dist + 1
            if cost < distance[n]:
                distance[n] = cost
                heapq.heappush(q,(cost, n))


N, M, K, X = map(int, input().split())
INF = int(1e9)
distance = [INF]*(N+1)
city = [[] for _ in range(N+1)]

for _ in range(M):
    A, B = map(int, input().split())
    city[A].append(B)


dijkstra(X)

check = 0
for i in range(1,N+1):
    if distance[i] == K:
        print(i)
        check = 1

if not check:
    print(-1)

