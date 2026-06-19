class Solution {
public:

    string encode(vector<string>& strs) {
        string str;
        for (string word: strs) {
            str += word + " ^";
        }
        return str;
    }

    vector<string> decode(string s) {
        string curr;
        vector<string> strs;
        for (unsigned int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && s[i+1] == '^') {
                strs.push_back(curr);
                ++i;
                curr = "";
            } else {
                curr += s[i];
            }
        }
        return strs;
    }
};
