from collections import deque

def printer(q,index,M):
    cnt = 0

    while q:
        nq = q.popleft()
        ni = index.popleft()
        if q and nq < max(q):
            q.append(nq)
            index.append(ni)
            continue
        cnt += 1
        if ni == M:
            return cnt


T = int(input())
for _ in range(T):
    N, M = map(int, input().split())

    index = deque([i for i in range(N)])
    priority = deque(list(map(int, input().split())))

    print(printer(priority,index, M))
