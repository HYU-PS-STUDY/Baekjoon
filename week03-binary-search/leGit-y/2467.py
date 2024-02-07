N = int(input())
arr = list(map(int, input().split()))

left, right = 0, N-1

min = abs(arr[left] + arr[right])
result_left = left
result_right = right

while left < right:
    add = arr[left] + arr[right]
    if add == 0:
        result_left = left
        result_right = right
        break

    if abs(add) < min:
        result_left = left
        result_right = right
        min = abs(add)

    # 음수일경우 0과 가까워지려면 add값을 키워줘야함 -> left 오른쪽 이동
    if add < 0:
        left += 1

    # 양수일경우 0과 가까워지려면 add값을 줄여줘야함 -> right 왼쪽 이동
    if add > 0:
        right -= 1

print(arr[result_left], arr[result_right])
