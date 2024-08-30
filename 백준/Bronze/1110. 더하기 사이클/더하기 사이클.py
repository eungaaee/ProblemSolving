N = int(input())
num = N
i = 0
while True:
    ten = num // 10
    one = num % 10
    num = one * 10 + (ten+one)%10
    i += 1
    if num == N:
        break
print(i)