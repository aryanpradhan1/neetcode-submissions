class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []

        for token in tokens:
            if token == "+" or token == "-" or token == "*" or token == "/":
                a = st.pop()
                b = st.pop()
                if token == "+":
                    st.append(a+b)
                elif token == "-":
                    st.append(b-a)
                elif token == "*":
                    st.append(a*b)
                else:
                    st.append(int(b / a))
            else:
                st.append(int(token))
        
        return st[-1]
            

