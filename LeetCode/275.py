# LeetCode
# Problem 275. H-Index II
# Difficulty level: Medium
# O(log(N)) solution, beats 100%

class Solution:
    def hIndex(self, citations):
        links = 0
        rechts = len(citations) - 1
        if len(citations) == 1:
            if citations[0] == 0:
                return 0
            else:
                return 1
        while links <= rechts:
            mitte = (links + rechts) // 2
            if citations[mitte] >= len(citations) - mitte:
                rechts = mitte - 1
            else:
                links = mitte + 1
        return len(citations) - links
    
solution = Solution()
print(solution.hIndex([0, 1, 3, 5, 6]))
print(solution.hIndex([1, 2, 100]))
print(solution.hIndex([0]))