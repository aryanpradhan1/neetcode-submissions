class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        int left = 0;
        int right = 0;
        set<char> chars;


        while (right < s.length()) {
            while (chars.contains(s[right])) {
                chars.erase(s[left]);
                left++;
            }
            chars.insert(s[right]);
            max = std::max(max, right - left + 1);
            right++;
        }
        return max;
    }
};
