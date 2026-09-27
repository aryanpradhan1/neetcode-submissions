class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left = 0
        right = 0
        best_profit = 0
        curr_min = sys.maxsize

        for i in range(len(prices)):
            if prices[i] < curr_min:
                curr_min = prices[i]

            if (prices[i] - curr_min > best_profit):
                best_profit = prices[i] - curr_min
        
        return best_profit
        


        



