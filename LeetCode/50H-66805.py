# LeetCode
# 34. Find First and Last Position of Element in Sorted Array
# Difficulty level: Medium
# 2 * log(N) solution using Binary Search
# 12/1/2025

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) == 0:
            return [-1, -1]
        vasen = 0
        oikea = len(nums) - 1
        while vasen <= oikea:
            keskella = (vasen + oikea) // 2
            if nums[keskella] <= target:
                vasen = keskella + 1
            else:
                oikea = keskella - 1
        if nums[oikea] != target:
            return [-1, -1]

        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return [l, oikea]

solution = Solution() 
nums1 = [5, 7, 7, 8, 8, 10]
target1 = 8
nums2 = [5, 7, 7, 8, 8, 10]
target2 = 6
nums3 = []
target3 = 0
print(solution.searchRange(nums1, target1))
print(solution.searchRange(nums2, target2))
print(solution.searchRange(nums3, target3))