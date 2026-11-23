class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = std::numeric_limits<int>::min();

        for (int pile : piles) {
            if (pile > max) {
                max = pile;
            }
        }

        if (piles.size() == h) {
            return max;
        }

        int result = 1;
        int left = 1;
        int right = max;

        while (left <= right) {
            int k = left + (right - left) / 2;

            if (works(piles, k, h)) {
                result = k;
                right = k - 1;
            } else {
                left = k + 1;
            }
        }

        return result;
    }

    bool works(vector<int>& piles, int k, int h) {
        long long total = 0;
        for (int p : piles) {
            total += ((p + k - 1) / k);
            if (total > h) {
                return false;
            }
        }

        return total <= h;
    }
};
