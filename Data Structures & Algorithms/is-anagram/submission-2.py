class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        letters = defaultdict(int)
        for letter in s:
            letters[letter] += 1
        
        for letter in t:
            if (letters.get(letter, 0) == 0):
                return False
            
            letters[letter] -= 1

        for key, value in letters.items():
            if value != 0:
                return False
        
        return True