import heapq
import sys
input = sys.stdin.readline

def dijkstra(start,distance):
    q = []
    heapq.heappush(q,(0,start))
    distance[start] = 0

    while q:
        dist, node = heapq.heappop(q)
        if distance[node] < dist:
            continue

        for n in graph[node]:
            n_dist, n_node = n
            cost = distance[node] + n_dist
            if cost < distance[n_node]:
                distance[n_node] = cost
                q.append((cost, n_node))


N, M, X = map(int, input().split())
graph = [[] for _ in range(N+1)]
INF = int(1e9)
come_distance = [INF] * (N+1)


for _ in range(M):
    s, e, t = map(int, input().split())
    graph[s].append((t,e))


dijkstra(X,come_distance)

max_dist = 0
for i in range(1, N+1):
    go_distance = [INF] * (N + 1)
    dijkstra(i, go_distance)
    total_dist = go_distance[X] + come_distance[i]
    max_dist = max(max_dist, total_dist)

print(max_dist)