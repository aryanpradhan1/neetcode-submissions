class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int left = 0;
        int right = 0;

        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                if (prices[right] - prices[left] >= max) {
                    max = prices[right] - prices[left];
                }
            }
            right++;
        }

        return max;
    }
};
