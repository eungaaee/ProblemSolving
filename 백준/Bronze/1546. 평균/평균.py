N = int(input())
score = list(map(int, input().split()))
max_score = max(score)
num = []
for i in range(N):
    num.append(score[i] / max_score * 100)
print(sum(num)/N)