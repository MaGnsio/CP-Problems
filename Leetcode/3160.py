from typing import List

class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        color, colors_frequency, result, unique_colors = {}, {}, [], 0
        for query in queries:
            i, c = query
            if color.get(i, 0) != 0:
                colors_frequency[color[i]] = colors_frequency[color[i]] - 1
                if colors_frequency[color[i]] == 0:
                    unique_colors = unique_colors - 1;
            color[i] = c
            if colors_frequency.get(color[i], 0) == 0:
                colors_frequency[color[i]] = 1
                unique_colors = unique_colors + 1
            else:
                colors_frequency[color[i]] = colors_frequency[color[i]] + 1
            result.append(unique_colors)
        return result

if __name__ == "__main__":
    solve = Solution()
    print(solve.queryResults(4, [[1, 4], [2, 5], [1, 3], [3, 4]]))
    print(solve.queryResults(4, [[0, 1], [1, 2], [2, 2], [3, 4], [4, 5]]))
