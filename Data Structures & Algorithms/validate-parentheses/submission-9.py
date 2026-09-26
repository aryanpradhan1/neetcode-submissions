class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        symbol_map = {')': '(', '}': '{', ']': '['};

        for i in range(len(s)):
            if (s[i] == '(' or s[i] == '[' or s[i] == '{'):
                st.append(s[i])
            else:
                if not st or symbol_map.get(s[i]) != st[-1]:
                    return False
                st.pop()
        
        return len(st) == 0
        