H, W, X, Y = map(int, input().split())

B = [list(map(int, input().split())) for _ in range(H+X)]
A = [[0]*(W+Y) for _ in range(H+X)]

for i in range(X):
    for j in range(W):
        A[i][j] = B[i][j]

for i in range(X, H+X):
    for j in range(Y):
        A[i][j] = B[i][j]
    for j in range(Y, W+Y):
        A[i][j] = B[i][j] - A[i-X][j-Y]

for i in range(H):
    for j in range(W):
        print(A[i][j], end = ' ')
    print()



