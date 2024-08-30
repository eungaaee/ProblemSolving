T = int(input())
for i in range(T):
    score = 0
    result = 0
    ox = list(input())
    for i in range(0, len(ox)):
        if ox[i] == 'O':
            score += 1
            result += score
        elif ox[i] == 'X':
            score = 0
    print(result)