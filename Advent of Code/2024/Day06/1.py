N, grid, visited = 130, list(), set()

for i in range(0, N):
    row = str(input())
    grid.append(row)

x, y, d = -1, -1, 0

for i in range(0, N):
    for j in range(0, N):
        if grid[i][j] == "^":
            x, y = i, j

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

visited.add((x, y))

while True:
    nx = x + dx[d]
    ny = y + dy[d]

    if nx < 0 or nx >= N:
        break
    if ny < 0 or ny >= N:
        break
    if grid[nx][ny] == '#':
        d = (d + 1) % 4
        continue

    x, y = nx, ny
    visited.add((x, y))

ans = int(len(visited))

print(ans)
