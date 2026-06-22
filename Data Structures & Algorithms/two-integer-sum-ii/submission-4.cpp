class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> diffs;
        vector<int> output;

        for (int i = 0; i < numbers.size(); ++i) {
            diffs[target - numbers[i]] = i;
            if (diffs.contains(numbers[i]) && diffs[numbers[i]] != diffs[target - numbers[i]]) {
                output.push_back(diffs[numbers[i]] + 1);
                output.push_back(diffs[target - numbers[i]] + 1);
                sort(output.begin(), output.end());
                return output;
            }
        }
    }
};
