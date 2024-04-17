import sys
input = sys.stdin.readline

def get_win_team():
    team_members = [0] * 201
    avail_team = []
    for a in arr:
        team_members[a] += 1
        if team_members[a] == 6:
            avail_team.append(a)

    team_score = [[] for _ in range(201)]
    score = 1
    for a in arr:
        if a not in avail_team:
            continue
        team_score[a].append(score)
        score += 1

    avail_team.sort(key=lambda x: (sum(team_score[x][:4]), team_score[x][4]))
    return avail_team[0]


T = int(input())
for _ in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    print(get_win_team())