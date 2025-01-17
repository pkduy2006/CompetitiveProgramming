# 81. Search in Rotated Sorted Array II
# Difficulty level: Medium
# 16/1/2025

class Solution:
    def search(self, nums, target):
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return True
            if nums[mid] == nums[l]:
                l += 1
                continue
            if nums[mid] < nums[l]:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
            else:
                if nums[l] <= target <= nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
        return False

solution = Solution()

nums1 = [2, 5, 6, 0, 0, 1, 2]
target1 = 0
print(solution.search(nums1, target1))

nums2 = [2, 5, 6, 0, 0, 1, 2]
target2 = 3
print(solution.search(nums2, target2))

nums3 = [1, 0, 1, 1, 1]
target3 = 0
print(solution.search(nums3, target3))

