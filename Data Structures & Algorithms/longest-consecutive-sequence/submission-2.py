class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        res = 0
        for num in num_set:
            streak = 0
            curr = num
            if curr - 1 not in num_set:
                streak = 0
                while curr in num_set:
                    streak += 1
                    curr += 1
                res = max(res, streak)
        return res



        


