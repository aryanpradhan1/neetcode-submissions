class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());

        maxLeft[0] = 0;
        for (int i = 1; i < height.size(); ++i) {
            maxLeft[i] = max(maxLeft[i - 1], height[i-1]);
        }

        maxRight[height.size() - 1] = 0;
        for (int i = height.size() - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], height[i+1]);
        }

        int water = 0;
        for (int i = 0; i < height.size(); ++i) {
            int waterAtIndex = max(min(maxLeft[i], maxRight[i]) - height[i], 0);
            water += waterAtIndex;
        }

        return water;
    }
};
