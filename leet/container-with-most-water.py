class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxA = 0
        for i, hi in enumerate(height):
            for j, hj in enumerate(height[i+1:]):
                maxA = max(maxA, min(hi,hj)*(j))
        return maxA

print(Solution().maxArea([1,8,6,2,5,4,8,3,7]))
