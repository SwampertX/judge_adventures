#!/usr/bin/env python


class Solution:
    def searchRange(self, nums, target):
        low, high = -1, -1
        l, r = 0, len(nums)
        m = (l + r) // 2
        while m in range(0, len(nums)) and l <= r:
            if nums[m] == target and (m == 0 or nums[m - 1] < target):
                low = m
                break
            else:
                if nums[m] < target:
                    l = m + 1
                else:
                    r = m - 1
            m = (l + r) // 2

        l, r = 0, len(nums)
        m = (l + r) // 2
        while m in range(0, len(nums)) and l <= r:
            if nums[m] == target and (m == len(nums) - 1 or nums[m + 1] > target):
                high = m
                break
            else:
                if nums[m] > target:
                    r = m - 1
                else:
                    l = m + 1
            m = (l + r) // 2
        return [low, high]
