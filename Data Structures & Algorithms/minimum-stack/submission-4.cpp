class MinStack {
    private:
        vector<int> st;
        vector<int> mins;

    public:
        
        MinStack() {}
        
        void push(int val) {
            if (mins.empty()) {
                mins.push_back(val);
            } else if (val < mins[mins.size() - 1]) {
                mins.push_back(val);
            } else {
                mins.push_back(mins[mins.size() - 1]);
            }
            st.push_back(val);

        }
        
        void pop() {
            st.pop_back();
            mins.pop_back();
        }
        
        int top() {
            return st[st.size() - 1];
        }
        
        int getMin() {
            return mins[mins.size() - 1];
        }
};
