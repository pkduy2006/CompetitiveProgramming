class Solution:
    def nextGreatestLetter(self, letters, target):
        links = 0
        rechts = len(letters) - 1
        while links <= rechts:
            mitte = (links + rechts) // 2
            if letters[mitte] <= target:
                links = mitte + 1
            else:
                rechts = mitte - 1
        if links < len(letters):
            return letters[links]
        return letters[0]

solution = Solution()
print(solution.nextGreatestLetter(["c", "f", "j"], "a"))
print(solution.nextGreatestLetter(["c", "f", "j"], "c"))
print(solution.nextGreatestLetter(["x", "x", "y", "y"], "z"))   