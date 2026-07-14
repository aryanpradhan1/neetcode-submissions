class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        map<char, char> symbols = {{')', '('}, {'}', '{'}, {']', '['}};
        if (s.size() % 2 == 1) {
            return false;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push_back(s[i]);
            } else {
                if (st.empty() || st.back() != symbols[s[i]]) {
                    return false;
                }
                st.pop_back();
            }
        }

        return st.size() == 0;


    }
};
