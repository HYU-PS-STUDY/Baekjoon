import sys
input = sys.stdin.readline

N = int(input())
H = list(map(int, input().split()))

H.sort()
min_diff = abs((H[3] + H[0]) - (H[1] + H[2]))
for i in range(N-3):
    for j in range(i+3, N):
        anna = H[i] + H[j]

        l = i+1
        r = j-1
        while l < r:
            elsa = H[l] + H[r]
            diff = abs(anna - elsa)
            min_diff = min(diff, min_diff)

            # 이 조건문을 통해 시간 훨씬 단축가능
            if min_diff == 0:
                print(0)
                exit()

            # elsa 가 더 큰 경우 -> elsa를 줄여야
            if anna < elsa:
                r -= 1
            else:
                l += 1

print(min_diff)


