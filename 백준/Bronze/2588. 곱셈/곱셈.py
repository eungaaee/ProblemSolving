inp1 = int(input())
inp2 = input()
out1 = inp1*int(inp2[-1])
out2 = inp1*int(inp2[-2])
out3 = inp1*int(inp2[-3])
out4 = inp1*int(inp2)

print(out1, out2, out3, out4, sep='\n')