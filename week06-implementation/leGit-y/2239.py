def column_valid(row,value):

    for j in range(9):
        if sudoku[row][j] == value:
            return 0

    return 1



def row_valid(column,value):

    for i in range(9):
        if sudoku[i][column] == value:
            return 0

    return 1


def square_valid(i,j,value):

    i = i // 3 * 3
    j = j // 3 * 3

    for a in range(i, i + 3):
        for b in range(j, j + 3):
            if sudoku[a][b] == value:
                return 0

    return 1

def dfs(cnt):
    if cnt == len(zero):
        return True

    r, c = zero[cnt]
    for i in range(1,10):
        if column_valid(r,i) and row_valid(c,i) and square_valid(r,c,i):
            sudoku[r][c] = i
            check = dfs(cnt + 1)
            if check:
                return True
            sudoku[r][c] = 0



sudoku = [list(map(int, input())) for _ in range(9)]
zero = []
for i in range(9):
    for j in range(9):
        if sudoku[i][j] == 0:
            zero.append((i,j))

dfs(0)
for i in range(9):
    for j in range(9):
        print(sudoku[i][j], end='')
    print()


