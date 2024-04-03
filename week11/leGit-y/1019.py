str = input()

N = int(str)
result = [0] * 10
digit = len(str)

# N = 3752
for i in range(len(str)):
    num = int(str[i])

    # str[i+1:] = 752 -> 52 -> 2
    if i == len(str)-1:
        count = 0
    else:
        count = int(str[i+1:])

    result[num] += count + 1

    tmp = 10 ** (digit - i - 1)
    if i == 0:
        for j in range(1,num):
            result[j] += tmp
        continue

    for j in range(num):
        result[j] += tmp

    for j in range(1,10):
        result[j] += tmp

    # str[:i] = 3 -> 37 -> 375
    for j in range(10):
        result[j] += (int(str[:i]) - 1) * tmp

print(*result)