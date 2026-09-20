class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        alpha_list = [0] * 26
        words = {}

        for word in strs:
            for i in word:
                alpha_list[ord(i) - ord('a')] += 1
            if tuple(alpha_list) not in  words:
                words[tuple(alpha_list)] = []
            words[tuple(alpha_list)].append(word)
            alpha_list = [0] * 26
        
        result = []
        for i in words:
            result.append(words[i])
        
        return result

        

