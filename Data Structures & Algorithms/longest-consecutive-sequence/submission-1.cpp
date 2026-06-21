class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> unique_nums;
        for (int num : nums) {
            unique_nums.insert(num);
        }

        set<int> starts;
        for (int num : unique_nums) {
            if (!unique_nums.contains(num - 1)) {
                starts.insert(num);
            }
        }

        int max_length = 0;
        int current_length = 1;
        int current_num;
        for (int num : starts) {
            current_num = num;
            current_length = 1;
            while (unique_nums.contains(current_num + 1)) {
                current_length += 1;
                current_num = current_num + 1;
            }
            if (current_length > max_length) {
                max_length = current_length;
            }
        }

        return max_length;

    }
};
