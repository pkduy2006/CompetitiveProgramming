class Solution:
    def search(self, nums, target):
        links = 0
        rechts = len(nums) - 1
        while links <= rechts:
            mitte = (links + rechts) // 2
            if nums[mitte] <= target:
                links = mitte + 1
            else:
                rechts = mitte - 1
        if nums[rechts] == target:
            return rechts
        return -1

solution = Solution()
print(solution.search([-1, 0, 3, 5, 9, 12], 9))
print(solution.search([-1, 0, 3, 5, 9, 12], 2))
