class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int low = 0;
        int high = heights.size() - 1;
        int maxArea = 0;

        while (low < high) {
            int currArea = min(heights[low], heights[high]) * (high - low);

            if (currArea > maxArea) {
                maxArea = currArea;
            }

            if (heights[low] < heights[high]) {
                low++;
            } else {
                high--;
            }
        }

        return maxArea;
    }
};
