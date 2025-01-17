# 33. Search in Rotated Sorted Array
# Difficulty level: Medium
# 15/1/2025

class Solution:
    def search(self, nums, target):
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < nums[l]:
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
            else:
                if nums[l] <= target <= nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
        return -1

solution = Solution()

nums1 = [4, 5, 6, 7, 0, 1, 2]
target1 = 0
print(solution.search(nums1, target1))

nums2 = [4, 5, 6, 7, 0, 1, 2]
target2 = 3
print(solution.search(nums2, target2))

nums3 = [1]
target3 = 0
print(solution.search(nums3, target3))

nums4 = [3, 5, 1]
target4 = 3
print(solution.search(nums4, target4))

nums5 = [5, 1, 3]
target5 = 5
print(solution.search(nums5, target5))

nums6 = [4, 5, 6, 7, 8, 1, 2, 3]
target6 = 8
print(solution.search(nums6, target6))