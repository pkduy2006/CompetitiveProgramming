class Solution:
    def isPerfectSquare(self, num):
        links = 0
        rechts = num // 2
        while links <= rechts:
            mitte = (links + rechts) // 2
            if mitte * mitte <= num:
                links = mitte + 1
            else:
                rechts = mitte - 1
        return rechts * rechts == num or num == 1

solution = Solution()
print(solution.isPerfectSquare(14))
print(solution.isPerfectSquare(16))