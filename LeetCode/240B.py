# LeetCode
# Problem 240. Search in a 2D Matrix II
# Difficulty level: Medium
# O(M + N) solution, beats 25.85%

class Solution:
    def searchMatrix(self, matrix, target):
        x = len(matrix) - 1
        y = 0
        while x >= 0 and y < len(matrix[0]):
            #print(matrix[x][y])
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] < target:
                y += 1
            else:
                x -= 1
            #print(x, y, end=' ')
            #print()
        return False

solution = Solution()

print(solution.searchMatrix([[1, 4, 7, 11, 15], [2, 5, 8, 11, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]], 5))
print(solution.searchMatrix([[1, 4, 7, 11, 15], [2, 5, 8, 11, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]], 20))
print(solution.searchMatrix([[-5]], -5))