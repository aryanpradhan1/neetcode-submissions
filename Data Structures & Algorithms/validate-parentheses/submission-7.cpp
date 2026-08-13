class Solution {
public:
    bool isValid(string s) {
        map<char, char> corresponding = {{')', '('}, {'}', '{'}, {']', '['}};
        vector<char> st;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push_back(s[i]);
            } else if (st.empty() || st.back() != corresponding[s[i]]) {
                return false;
            } else {
                st.pop_back();
            }

        }

        return st.size() == 0;
    }
};
