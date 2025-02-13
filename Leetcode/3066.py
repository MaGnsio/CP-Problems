from typing import List
from sortedcontainers import SortedList

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        ans = 0
        s = SortedList(nums)
        while True:
            if s[0] >= k:
                break
            x, y = s[0], s[1]
            z = 2 * s[0] + s[1]
            s.remove(x), s.remove(y), s.add(z)
            ans = ans + 1
        return ans

if __name__ == "__main__":
    solve = Solution()
    print(solve.minOperations([2,11,10,1,3], 10))
    print(solve.minOperations([1,1,2,4,9], 20))
