def func():
    result = []

    for ar in arr:
        plus = 0
        split_by_plus = ar.split('+')

        for num in split_by_plus:
            plus += int(num)
        result.append(plus)

    answer = result[0]
    for i in range(1,len(result)):
        answer -= result[i]

    return answer


math = input()
arr = math.split('-')
print(func())