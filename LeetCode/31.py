# 31. Next Permutation
# Difficulty level: Medium
# Time: 22.38 (UTC +02:00), 5/1/2025, Helsinki

class Solution:
    def nextPermutation(self, nums):
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1:] = reversed(nums[i + 1:])

solution = Solution()
nums1 = [1, 2, 3]
nums2 = [3, 2, 1]
nums3 = [1, 1, 5]
solution.nextPermutation(nums1)
solution.nextPermutation(nums2)
solution.nextPermutation(nums3)
print(nums1)
print(nums2)
print(nums3)