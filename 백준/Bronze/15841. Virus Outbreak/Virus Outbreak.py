max = 0
v1 = []
v2 = [1, 1]
while(1):
    t = int(input())
    if t<0:
        break
    v1.append(t)
    if t>max:
        max = t
for i in range(1, max):
    v2.append(v2[i-1]+v2[i])
for i in v1:
    print(f"Hour {i}: {v2[i-1]} cow(s) affected")