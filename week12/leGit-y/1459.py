import sys
input = sys.stdin.readline

X, Y, W, S = map(int, input().split())

result = -1
move = X+Y


# 2*블록 > 대각선
# 최대한 대각선으로 이동
if 2 * W > S:
    # 지그재그(대각선)로 돌아가더라도 돌아가는게 더 빠른 경우
    if W > S:
        # 대각선으로만 이동이 가능한 좌표일 경우
        if move % 2 == 0:
            result = S * max(X,Y)
        else:
            result = S * (max(X,Y) - 1) + W
    # 돌아가지지 않고 직진하는게 더 빠른 경우
    else:
        result = min(X, Y) * S + abs(X - Y) * W

# 2*블록 <= 대각선
# 최대한 가로,세로로 이동
else:
    result = W * move


print(result)









