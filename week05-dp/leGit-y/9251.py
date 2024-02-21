A = input()
B = input()

N1 = len(A)
N2 = len(B)

result = [[0] * (N2+1) for _ in range(N1+1)]

for i in range(1, N1+1):
    for j in range(1, N2+1):

        if A[i-1] == B[j-1]:
            result[i][j] = result[i-1][j-1] + 1

        else:
            result[i][j] = max(result[i-1][j], result[i][j-1])

print(result[N1][N2])
