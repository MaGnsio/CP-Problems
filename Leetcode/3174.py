class Solution:
    def clearDigits(self, s: str) -> str:
        n, result = len(s), ""
        removed = [False] * n
        for i in range(0, n):
            if s[i].isdigit():
                removed[i] = True
                for j in reversed(range(0, i)):
                    if not removed[j]:
                        removed[j] = True
                        break
        for i in range(0, n):
            if not removed[i]:
                result = result + s[i]
        return result

if __name__ == "__main__":
    solve = Solution()
    print(solve.clearDigits("cb34"))
    print(solve.clearDigits("abc"))
