# LeetCode
# 162. Find Peak Element
# Difficulty level: Medium
# beats 100%, using binary search

class Solution:
    def findPeakElement(self, nums):
        links = 0
        rechts = len(nums) - 1
        if len(nums) == 2:
            if nums[0] < nums[1]:
                return 1
            else:
                return 0
        if len(nums) == 1:
            return 0
        while links < rechts:
            mitte = (links + rechts) // 2
            if nums[mitte] > nums[links] and nums[mitte] > nums[rechts]:
                links += 1
                rechts -= 1
            elif nums[links] < nums[mitte] < nums[rechts]:
                links = mitte + 1
            elif nums[links] > nums[mitte] > nums[rechts]:
                rechts = mitte - 1
            else:
                if nums[links] > nums[rechts]:
                    rechts = mitte - 1
                else:
                    links = mitte + 1
        return links
    
solution = Solution()
print(solution.findPeakElement([1, 2, 3, 1]))
print(solution.findPeakElement([1, 2, 1, 3, 5, 6, 4]))
print(solution.findPeakElement([1, 2]))
print(solution.findPeakElement([3, 1, 2]))