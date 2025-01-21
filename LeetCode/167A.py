# LeetCode
# 167. Two Sum II - Input Array Is Sorted
# Difficulty level: Medium
# Solution using binary search, beats 6.40%

class Solution:
    def twoSum(self, numbers, target):
        for i in range(len(numbers)):
            a = target - numbers[i]
            links = i + 1
            rechts = len(numbers) - 1
            while links <= rechts:
                mitte = (links + rechts) // 2
                if numbers[mitte] <= a:
                    links = mitte + 1
                else:
                    rechts = mitte - 1
            #print(numbers[i], numbers[rechts])
            if numbers[rechts] + numbers[i] == target:
                return [i + 1, rechts + 1]

solution = Solution()
print(solution.twoSum([2, 7, 11, 15], 9))
print(solution.twoSum([2, 3, 4], 6))
print(solution.twoSum([-1, 0], -1))
print(solution.twoSum([3, 24, 50, 79, 88, 150, 345], 200))