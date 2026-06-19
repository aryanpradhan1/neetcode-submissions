#include <map>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int, int> indices;
        vector<int> output;
        for (unsigned int i = 0; i < nums.size(); ++i) {
            indices[i] = nums[i];
        }

        for (int j = 0; j < nums.size(); ++j) {
            int num = 1;
            for (const auto& duo : indices) {
                if (duo.first != j) {
                    num *= duo.second;
                } 
            }
            output.push_back(num);
        }
        return output;
    }
};
