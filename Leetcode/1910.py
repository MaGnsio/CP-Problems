class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        n, m = len(s), len(part)
        while True:
            for i in range(0, n - m + 1):
                if s[i : i + m] == part:
                    s = s[:i] + s[i + m:]
                    break
            if len(s) == n:
                break
            n = len(s)
        return s


if __name__ == "__main__":
    solve = Solution()
    print(solve.removeOccurrences("daabcbaabcbc", "abc"))
