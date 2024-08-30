C = int(input())
for i in range(C):
    N = list(map(int, input().split()))
    avg = sum(N[1:])/N[0]
    over = 0
    for i in N[1:]:
        if i > avg:
            over += 1
    result = over/N[0]*100
    print(f"{result:.3f}%")