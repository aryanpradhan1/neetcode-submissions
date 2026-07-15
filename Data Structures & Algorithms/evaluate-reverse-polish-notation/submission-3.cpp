class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        set<string> operators = {"+", "-", "*", "/"};

        vector<int> res;
        for (int i = 0; i < tokens.size(); ++i) {
            if (!(operators.contains(tokens[i]))) {
                res.push_back(stoi(tokens[i]));
            } else if (tokens[i] == "+") {
                int result = res[res.size() - 2] + res[res.size() - 1];
                res.pop_back();
                res.pop_back();
                res.push_back(result);
            } else if (tokens[i] == "-") {
                int result = res[res.size() - 2] - res[res.size() - 1];
                res.pop_back();
                res.pop_back();
                res.push_back(result);
            } else if (tokens[i] == "*") {
                int result = res[res.size() - 2] * res[res.size() - 1];
                res.pop_back();
                res.pop_back();
                res.push_back(result);
            } else if (tokens[i] == "/") {
                int result = res[res.size() - 2] / res[res.size() - 1];
                res.pop_back();
                res.pop_back();
                res.push_back(result);
            }      
        }

        return res[0];
    }
};
