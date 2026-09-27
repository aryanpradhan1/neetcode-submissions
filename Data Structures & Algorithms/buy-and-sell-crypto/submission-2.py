class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left = 0
        right = 0
        best_profit = 0
        curr_min = prices[0]

        while right < len(prices):
            if (prices[right] < curr_min):
                curr_min = prices[right]
                left = right
            
            if (prices[right] - prices[left] > best_profit):
                best_profit = prices[right] - prices[left] 
            
            right += 1
    
        return best_profit
        


        



