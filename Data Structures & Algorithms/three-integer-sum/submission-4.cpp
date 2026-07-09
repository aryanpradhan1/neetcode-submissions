class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sols;

        
        for (int slow = 0; slow < nums.size() - 1; ++slow) {
            if (slow > 0 && nums[slow] == nums[slow - 1]) {
                continue;
            }

            int temp = slow + 1;
            int fast = nums.size() - 1;
            
            while (temp < fast) {
                int currTotal = nums[slow] + nums[temp] + nums[fast];

                if (currTotal == 0) {
                    sols.push_back({nums[slow], nums[temp], nums[fast]});
                    temp++;
                    fast--;
                    while (temp < fast && nums[temp] == nums[temp - 1]) {
                        temp++;
                    }
                } else if (currTotal < 0) {
                    temp++;
                } else {
                    fast--;
                }
            }    
        }

        return sols;
    }

};
