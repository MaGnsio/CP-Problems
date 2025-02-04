class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        n, result, current = len(nums), nums[0], nums[0]
        for i in range(1, n):
            if nums[i - 1] < nums[i]:
                current = current + nums[i]
            else:
                current = nums[i]
            result = max(result, current)
        return result
