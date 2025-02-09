from typing import List

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        mp : dict[int, int] = {}
        for i in range(0, n):
            x = i - nums[i]
            if mp.get(x, 0) == 0:
                mp[x] = 0
            mp[x] = mp[x] + 1
        ans = n * (n - 1) // 2
        for _, x in mp.items():
            ans = ans - x * (x - 1) // 2
        return ans


if __name__ == "__main__":
    solve = Solution()
    print(solve.countBadPairs([4,1,3,3]))
    print(solve.countBadPairs([1,2,3,4,5]))
