class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        b = sorted(nums)
        for _ in range(0, n):
            if nums == b:
                return True
            x = b[n - 1] 
            b.pop(-1)
            b.insert(0, x)
        return False
