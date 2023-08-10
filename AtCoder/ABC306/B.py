ans = 0
a = list(map(int, input().strip().split()))
for i in range(0, 64):
    ans = ans + a[i] * (1 << i)
print(ans)