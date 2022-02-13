class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left = 0
        right = 1
        max_profit = 0

        for i in range(len(prices)-1):
            current_profit = prices[right]-prices[left]

            if prices[right] < prices[left]:
                left = right
                right += 1
                continue

            max_profit = max(current_profit, max_profit)
            right += 1
        return max_profit
        