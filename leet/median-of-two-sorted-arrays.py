class Solution:
    # returns index of ceiling
    def bs(val: int, nums: List[int]) -> int:
        l, r = 0, len(nums)
        m = (l+r)//2
        # left <= val and curr > val
        if (m == 0 && 
        if nums[m-1] <= 
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        il, ir = 0, m
        jl, jr = 0, n

        if (m+n)%2 == 1: #odd
            half = (m+n)//2
            im = m//2
            jm = bs(nums2, nums1[im])
            while(im+jm != half):
                if (im+jm) == half:
                    return nums1[im]
                # median im is too big
                else if im + jm > half:
                    ir = im
                    im = (il + ir)//2
                    jm = bs(nums2, nums1[im])
                else: # too small
                    il = im
                    im = (il + ir)//2
                    jm = bs(nums2, nums1[im])

        else:
            half = (m+n)/2
            # must find two numbers such that > half and half-1
            im = m//2
            jm = bs(nums2, nums1[im])
            ans1, ans2 = 0,0
            while(im+jm != half):
                if (im+jm) == half:
                    ans1 = nums1[im]
                # median im is too big
                else if (im + jm) > half:
                    ir = im
                    im = (il + ir)//2
                    jm = bs(nums2, nums1[im])
                else: # too small
                    il = im
                    im = (il + ir)//2
                    jm = bs(nums2, nums1[im])
            im = m//2
            jm = bs(nums2, nums1[im])
            half = (m+n)/2-1
            while(im+jm != half-1):
                if (im+jm) == half:
                    ans2 = nums1[im]
                # median im is too big
                else if (im + jm) > half:
                    ir = im
                    im = (il + ir)//2
                    jm = bs(nums2, nums1[im])
                else: # too small
                    il = im
                    im = (il + ir)//2
                    jm = bs(nums2, nums1[im])
            return (ans1 + ans2)/2
