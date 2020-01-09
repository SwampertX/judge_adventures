def longestPalindrome(s: str) -> str:
    ans = ""
    for i in range(len(s)-1):
        # odd palindrome
        left, right = i, i
        while left >= 0 and right < len(s) and s[left] == s[right]:
            ans = s[left:right+1]
            left -= 1
            right += 1
        # even palindrome
        left, right = i, i+1
        while left >= 0 and right < len(s) and s[left] == s[right]:
            ans = s[left:right+1]
            left -= 1
            right += 1
    return ans
