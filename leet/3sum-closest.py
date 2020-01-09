import math

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        closest = target
        for i, vi in enumerate(nums):
            numsj = nums[:i]+nums[i+1:]
            for j, vj in enumerate(numsj):
                numsk = nums[:j]+nums[j+1:]
                for k, vk in enumerate(numsk):
                    temp_sum = vi + vj + vk
                    if math.fabs(temp_sum - target) < math.fabs(closest - target):
                        closest = temp_sum
