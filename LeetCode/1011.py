# 1011. Capacity To Ship Packages Within D Days
# Difficulty level: Medium
# Time: 13.51 (UTC +02.00), 11/1/2025, Helsinki
# N log(N) solution using binary search

class Solution(object):
    def shipWithinDays(self, weights, days):
        def check(capacity):
            cnt = 0
            actual_days = 0
            for i in weights:
                if cnt + i <= capacity:
                    cnt += i
                else:
                    cnt = i
                    actual_days += 1
            if cnt > 0:
                actual_days += 1
            return actual_days <= days
        
        vasen = max(weights)
        oikea = 0
        for i in weights:
            oikea += i
        while vasen <= oikea:
            keskella = (vasen + oikea) // 2
            if check(keskella):
                oikea = keskella - 1
            else:
                vasen = keskella + 1
        return vasen

solution = Solution()
weights1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
days1 = 5
weights2 = [3, 2, 2, 4, 1, 4]
days2 = 3
weights3 = [1, 2, 3, 1, 1]
days3 = 4
print(solution.shipWithinDays(weights1, days1))
print(solution.shipWithinDays(weights2, days2))
print(solution.shipWithinDays(weights3, days3))