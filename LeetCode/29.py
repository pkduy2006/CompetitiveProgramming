# 29. Divide Two Integers
# Difficulty level: Medium
# Time: 15h49 4/1/2025 (UTC +02:00) Helsinki

import math

int_max = 2147483647
int_min = -2147483648

class Solution:
    def divide(self, dividend, divisor):
        ans = math.trunc(dividend / divisor)
        if int_min <= ans <= int_max:
            return ans
        elif int_min > ans:
            return int_min
        else:
            return int_max

solution = Solution()
print(solution.divide(10, 3))
print(solution.divide(7, -3))
print(solution.divide(-2147483648, -1))