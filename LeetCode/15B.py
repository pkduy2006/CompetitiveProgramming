# 15. 3Sum
# Difficulty level: Medium
# Time: 02.12 (UTC +02.00), 6/1/2025, Helsinki
# N^2 solution using 2 pointers

class Solution:
    def threeSum(self, nums):
        nums.sort()
        result = [] 

        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            l = i + 1
            r = len(nums) - 1
            while l < r:
                total = nums[i] + nums[l] + nums[r]

                if total == 0:
                    result.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif total < 0:
                    l += 1
                else:
                    r -= 1 

        return result
    
solution = Solution()
print(solution.threeSum([-1, 0, 1, 2, -1, -4]))
print(solution.threeSum([0, 1, 1]))
print(solution.threeSum([0, 0, 0]))
print(solution.threeSum([0, 0, 0, 0]))