class Solution:
    def reverse(self, x:int) -> int:
        return 0 if (x == 2**31) else (int(str(x)[::-1]) if x >=0 else -int(str(x)[::-1]))
