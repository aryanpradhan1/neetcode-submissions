class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums[nums.size() - 1] > nums[0]) {
            return nums[0];
        }

        int result = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int k = left + (right - left) / 2;
            
            if ((k - 1) < 0) {
                if (k + 1 >= nums.size()) {
                    return nums[k];
                }
                left = k + 1;
            } else if (nums[k - 1] > nums[k]) {
                result = nums[k];
                return nums[k];
            } else if (nums[k] > nums[right]) {
                left = k + 1;
            } else {
                right = k-1;
            }
            
        }
        return result;
    }
};
