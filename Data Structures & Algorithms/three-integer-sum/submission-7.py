class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        if len(nums) == 0:
            return []

        result = []

        for i in range(len(nums) - 1):
            if (i > 0 and nums[i] == nums[i - 1]):
                continue

            j = i + 1
            k = len(nums) - 1
            
            target = 0 - nums[i]
            while (j < k):
                if (j != i and k != i and nums[j] + nums[k] == target):
                    result.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while (j < k and nums[j-1] == nums[j]):
                        j += 1
                    
                elif (j != i and k != i and nums[j] + nums[k] < target):
                    j += 1
                elif (j != i and k != i and nums[j] + nums[k] > target):
                    k -= 1
                elif j == i:
                    j += 1
                elif k == i:
                    k -= 1
        
        return result
            