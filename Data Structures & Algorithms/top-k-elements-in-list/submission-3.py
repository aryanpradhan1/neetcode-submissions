class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_map = defaultdict(int)
        result = []

        for num in nums:
            freq_map[num] += 1

        for number, freq in freq_map.items():
            result.append((freq, number))

        result.sort(reverse = True)

        answer = []

        for i in range(k):
            answer.append(result[i][1])
        
        return answer
        

        