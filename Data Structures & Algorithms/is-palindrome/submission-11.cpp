class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        if (s.size() == 1) {
            return true;
        }
        

        for (left; left <= right; ++left) {
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            while (left < right && !isalnum(s[left])) {
                left++;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                cout << s[left] << endl;
                cout << s[right] << endl;
                return false;
            }
            right--;
        }

        return true;
    }
};
