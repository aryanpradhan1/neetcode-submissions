class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> freq_map;
        int l = 0;
        int r = 0;
        int freqchar = 0;
        int windowlen = 0;
        int result = 0;

        for (r; r < s.size(); r++) {
            freq_map[s[r]] += 1;
            windowlen = r - l + 1;

            for (auto ch : freq_map) {
                if (ch.second > freqchar) {
                    freqchar = ch.second;
                }
            }

            if (windowlen - freqchar <= k) {
                if (result < windowlen) {
                    result = windowlen;
                }
            } else {
                freq_map[s[l]] -= 1;
                l++;
            }
        }

        return result;
    }
};
