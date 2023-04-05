/**
 *    author:  MaGnsi0
 *    created: 06.03.2023 14:11:35
**/
import math

m, n, p = map(int, input().split())
if n > p:
    print("0/1")
    exit()
dp = [[-1 for i in range(n)] for j in range(p)]

def solve(x, y):
    if x == p and y == n:
        return 1
    if x == p or y == n:
        return 0
    if dp[x][y] != -1:
        return dp[x][y]
    dp[x][y] = (m - x - 2 * (n - y)) * solve(x + 1, y) + 2 * (n - y) * solve(x + 1, y + 1)
    return dp[x][y]

ans1 = solve(0, 0)
for i in range(1, m - p + 1):
    ans1 = i * ans1
ans2 = 1
for i in range(1, m + 1):
    ans2 = i * ans2

g = math.gcd(ans1, ans2)
print(int(ans1 / g), end = "")
print("/", end = "")
print(int(ans2 / g), end = "")
