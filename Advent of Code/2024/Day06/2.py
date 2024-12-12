ans, N, grid = 0, 130, list()

for i in range(0, N):
    row = str(input())
    grid.append(row)

x_, y_, d_ = -1, -1, 0

for i in range(0, N):
    for j in range(0, N):
        if grid[i][j] == "^":
            x_, y_ = i, j

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


for i in range(0, N):
    for j in range(0, N):
        if grid[i][j] != ".":
            continue

        cycle: bool = False
        visited = set()
        x, y, d = x_, y_, d_
        visited.add((x, y, d))

        while True:
            nx = x + dx[d]
            ny = y + dy[d]

            if nx < 0 or nx >= N:
                break
            if ny < 0 or ny >= N:
                break

            if (grid[nx][ny] == '#') or (nx == i and ny == j):
                d = (d + 1) % 4
                continue
            
            x, y = nx, ny
            if (x, y, d) in visited:
                cycle = True
                break

            visited.add((x, y, d))
        if cycle:
            ans = ans + 1

print(ans)

