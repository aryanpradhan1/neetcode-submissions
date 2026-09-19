class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numbers = defaultdict(int)

        output = []

        for i in range(len(nums)):
            if (numbers.get(nums[i]) is None):
                numbers[target - nums[i]] = i
            else:
                if numbers[nums[i]] < i:
                    output.append(numbers[nums[i]])
                    output.append(i)
                else:
                    output.append(i)
                    output.append(numbers[nums[i]])
                return output