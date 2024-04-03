def solve():
    dp[0] = arr[0]
    if n == 1:
        return
    dp[1] = arr[0] + arr[1]
    if n == 2:
        return

    dp[2] = max(arr[0] + arr[1], arr[1] + arr[2], arr[0] + arr[2])

    # dp[i]: i번째 포도주까지 마셨을때, 최대로 마신 포도주 양
    for i in range(3, n):
        # [CASE 1] 안마시고-마시고-마시고
        case_1 = dp[i - 3] + arr[i - 1] + arr[i]

        # [CASE 2] 마시고-안마시고-마시고
        case_2 = dp[i - 2] + arr[i]

        # [CASE 3] 안마시고-마시고-마시고-안마시고
        case_3 = dp[i - 1]

        dp[i] = max(case_1, case_2, case_3)
    return

n = int(input())
arr = [-1] * n
dp = [0] * n
for i in range(n):
    num = int(input())
    arr[i] = num

solve()
print(dp[n-1])