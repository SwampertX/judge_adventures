class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        for idx in range(nums.len):
            hash_map[nums[idx]] = idx
        for i in nums:
            if i in hash_map and (target - i) in hash_map:
                return [hash_map[i], hash_map[target - i]]
