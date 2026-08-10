class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1arr[26] = {0};
        int s2arr[26] = {0};

        if (s1.size() > s2.size()) return false;

        for (int i = 0; i < s1.size(); ++i) {
            s1arr[s1[i] - 'a']++;
        }

        for (int l = 0; l < s2.size() - s1.size() + 1; ++l) {
            string window = s2.substr(l, s1.size());
            for (int j = 0; j < window.size(); ++j) {
                s2arr[window[j] - 'a']++;
            }

            if (equal(begin(s1arr), end(s1arr), begin(s2arr))) return true;
            fill(begin(s2arr), end(s2arr), 0);
        }

        return false;
    }
};
