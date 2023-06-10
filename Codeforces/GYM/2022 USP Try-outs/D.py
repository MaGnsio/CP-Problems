n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
sum, tot, dp = 1, 1, 0
for x in b:
    sum = int(sum * x)
for x in a:
    tot = int(x * tot)
for x in a:
    take = True
    for y in b:
        if x == y:
            take = False
            break
    if take:
        dp = int(dp + int(tot // x))
if sum == dp:
    print("S")
else:
    print("N")
