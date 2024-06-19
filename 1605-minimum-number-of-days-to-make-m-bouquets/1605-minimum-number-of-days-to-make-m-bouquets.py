class Solution(object):
    def canMakeBouquets(self, bloomDay, m, k, day):
        """
        Helper function to check if we can make m bouquets with k adjacent flowers by a given day.
        """
        bouquets = 0
        flowers = 0
        
        for bloom in bloomDay:
            if bloom <= day:
                flowers += 1
                if flowers == k:
                    bouquets += 1
                    flowers = 0
            else:
                flowers = 0
        
        return bouquets >= m

    def minDays(self, bloomDay, m, k):
        """
        :type bloomDay: List[int]
        :type m: int
        :type k: int
        :rtype: int
        """
        n = len(bloomDay)
        if m * k > n:
            return -1  # Not enough flowers to make m bouquets
        
        low = min(bloomDay)
        high = max(bloomDay)
        
        while low < high:
            mid = low + (high - low) // 2  # Avoid overflow
            if self.canMakeBouquets(bloomDay, m, k, mid):
                high = mid  # Try to find a smaller day
            else:
                low = mid + 1  # Try to find a larger day
        
        return low

# Example usage:
solution = Solution()
bloomDay = [1, 10, 3, 10, 2]
m = 3
k = 1
print(solution.minDays(bloomDay, m, k))  # Output: 3
