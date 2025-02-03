class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n, ans = len(nums), 1
        for i in range(0, n):
            inc, dec = 1, 1
            for j in range(i + 1, n):
                if nums[j] <= nums[j - 1]:
                    break
                inc = inc + 1
            for j in range(i + 1, n):
                if nums[j] >= nums[j - 1]:
                    break
                dec = dec + 1
            ans = max(ans, inc)
            ans = max(ans, dec)
        return ans
