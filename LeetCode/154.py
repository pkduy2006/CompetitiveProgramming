# LeetCode
# Problem 154: Find Minimum in Rotated Sorted Array II
# Difficulty level: Hard

class Solution:
    def findMin(self, nums):
        links = 0
        rechts = len(nums) - 1
        while links < rechts:
            mitte = (links + rechts) // 2
            if nums[links] < nums[mitte] <= nums[rechts]:
                return nums[links]
            elif nums[links] == nums[mitte] == nums[rechts]:
                links += 1
                rechts -= 1
            elif nums[links] > nums[mitte] and nums[mitte] <= nums[rechts]:
                links += 1
                rechts = mitte
            elif nums[links] == nums[mitte] < nums[rechts]:
                return nums[links]
            else:
                links = mitte + 1
        return nums[rechts]

solution = Solution()

print(solution.findMin([1, 3, 5]))
print(solution.findMin([2, 2, 2, 0, 1]))
print(solution.findMin([3, 3, 3, 3, 3, 3, 3, 3, 1, 3]))
print(solution.findMin([1, 1]))
print(solution.findMin([2, 2, 0, 0, 1, 1]))
print(solution.findMin([1, 3, 3]))
print(solution.findMin([1, 1, 3, 1]))
print(solution.findMin([10, 1, 10, 10, 10]))