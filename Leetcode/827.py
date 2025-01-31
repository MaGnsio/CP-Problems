class Solution(object):
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n, p = len(grid), 0
        parent = [[-1] * n for _ in range(n)]

        def dfs(x, y):
            parent[x][y] = p
            dx = [-1, 0, 0, 1]
            dy = [0, -1, 1, 0]
            for i in range(0, 4): 
                nx = x + dx[i]
                ny = y + dy[i]
                if nx < 0 or nx >= n:
                    continue
                if ny < 0 or ny >= n:
                    continue
                if grid[nx][ny] == 0:
                    continue
                if parent[nx][ny] != -1:
                    continue
                dfs(nx, ny)

        for i in range(0, n):
            for j in range(0, n):
                if parent[i][j] != -1:
                    continue
                if grid[i][j] == 0:
                    continue
                dfs(i, j)
                p = p + 1

        sizes = [0] * p
        for i in range(0, n):
            for j in range(0, n):
                if grid[i][j] == 0:
                    continue
                print(f"{i} {j}: {parent[i][j]}")
                sizes[parent[i][j]] = sizes[parent[i][j]] + 1

        ans = 0
        for i in range(0, p):
            ans = max(ans, sizes[i])

        for i in range(0, n):
            for j in range(0, n):
                if grid[i][j] == 1:
                    continue
                s = set()
                dx = [-1, 0, 0, 1]
                dy = [0, -1, 1, 0]
                for k in range(0, 4): 
                    ni = i + dx[k]
                    nj = j + dy[k]
                    if ni < 0 or ni >= n:
                        continue
                    if nj < 0 or nj >= n:
                        continue
                    if grid[ni][nj] == 0:
                        continue
                    s.add(parent[ni][nj])

                val = 1
                for x in s:
                    val = val + sizes[x]
                ans = max(ans, val)

        return ans

