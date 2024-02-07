import sys
input = sys.stdin.readline

def is_in_list(target):
    left, right = 0, N-1
    while left <= right:
        mid = (left + right) // 2

        if arr[mid] < target:
            left = mid + 1
        elif arr[mid] > target:
            right = mid - 1
        else:
            return 1

    return 0


N = int(input())
arr = list(map(int, input().split()))
arr.sort()

M = int(input())
num = map(int, input().split())
for n in num:
    print(is_in_list(n))
