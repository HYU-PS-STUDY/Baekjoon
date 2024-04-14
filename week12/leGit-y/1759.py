"""
조건: 최소 1개의 모음 + 최소 2개의 자음
증가하는 순서로 배열
"""
import sys
input = sys.stdin.readline

L, C = map(int, input().split())
alpha = list(input().split())


alpha.sort()
result = []

def check_vowel(alpha):
    if alpha == 'a' or alpha == 'e' or alpha == 'i' or alpha == 'o'\
        or alpha == 'u':
        return 0
    return 1

def _print():
    for a in result:
        print(a, end='')
    print()

"""
check_1 : 모음 개수 체크
check_2 : 자음 개수 체크
"""
def dfs(depth, idx, check_1, check_2):
    if depth == L:
        if check_1 >= 1 and check_2 >= 2:
            _print()
        return

    for i in range(idx, C):
        check = check_vowel(alpha[i])
        if check:
            check_2 += 1
        else:
            check_1 += 1

        result.append(alpha[i])
        dfs(depth+1, i+1, check_1, check_2)
        result.pop()
        if check:
            check_2 -= 1
        else:
            check_1 -= 1


dfs(0,0,0,0)
