class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        left = 0
        right = 0
        letters = set()
        max_length = 0

        while (right < len(s)):
            if (s[right] not in letters):
                letters.add(s[right])
                right += 1
            else:
                while (s[right] in letters):
                    letters.remove(s[left])
                    left += 1
            if (len(letters) > max_length):
                max_length = len(letters)
        
        return max_length