class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() * matrix[0].size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int m = mid / matrix[0].size();
            int n = mid % matrix[0].size();

            if (matrix[m][n] == target) {
                return true;
            } else if (matrix[m][n] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
