# LeetCode
# Problem 153: Find Minimum in Rotated Sorted Array
# Difficulty level: Medium

class Solution:
    def findMin(self, nums):
        if nums[0] < nums[-1]:
            return nums[0]
        vasen = 0
        oikea = len(nums) - 1
        while vasen != oikea:
            keskella = (vasen + oikea) // 2
            #print(nums[vasen], nums[keskella], nums[keskella + 1], nums[oikea])
            if nums[keskella] < nums[keskella + 1]:
                if nums[vasen] < nums[keskella] and nums[keskella + 1] < nums[oikea]:
                    oikea = keskella
                elif nums[keskella + 1] > nums[oikea]:
                    vasen = keskella
                else:
                    oikea = keskella
            else:
                return nums[keskella + 1]
        return nums[vasen]

solution = Solution()

print(solution.findMin([3, 4, 5, 1, 2]))
print(solution.findMin([4, 5, 6, 7, 0, 1, 2]))
print(solution.findMin([11, 13, 15, 17]))
print(solution.findMin([1]))
print(solution.findMin([3, 1, 2]))