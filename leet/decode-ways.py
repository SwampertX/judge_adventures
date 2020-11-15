#!/usr/bin/env python3


class Solution:
    def __init__(self):
        self.valid = {str(i) for i in range(1, 27)}
        self.memo = {"": 1}

    def numDecodings(self, s: str) -> int:
        if s in self.memo.keys():
            return self.memo[s]

        self.memo[s] = 0
        if s[:1] in self.valid:
            self.memo[s] += self.numDecodings(s[1:])
        if s[:2] in self.valid:
            self.memo[s] += self.numDecodings(s[2:])

        return self.memo[s]

    # def numDecodings(self, s: str) -> int:
    #     # a queue of tuples, (string, sum so far)
    #     num = 0
    #     queue = [(s, 1)]
    #     while len(queue) != 0:
    #         # print("queue " + str(queue))
    #         curr = queue.pop(0)
    #         currStr = curr[0]
    #         currSum = curr[1]
    #         if currStr == "":
    #             num += currSum
    #             continue
    #         if (
    #             len(currStr) >= 1
    #             # and self.isValidEncoding(currStr[1:])
    #             and self.isValidEncoding(currStr[:1])
    #         ):
    #             # print(currStr[1:] + " is valid")
    #             queue.append((currStr[1:], currSum))
    #         if (
    #             len(currStr) >= 2
    #             # and self.isValidEncoding(currStr[2:])
    #             and self.isValidEncoding(currStr[:2])
    #         ):
    #             # print(currStr[2:] + " is valid")
    #             queue.append((currStr[2:], currSum))
    #     return num

    # def isValidEncoding(self, s: str) -> bool:
    #     if len(s) == 0:
    #         return True
    #     elif len(s) == 1:
    #         return int(s) != 0
    #     else:  # length >= 2
    #         return int(s[0]) != 0 and 0 < int(s[:2]) <= 26

    def test(self):
        print(self.numDecodings("27"))
        print(self.numDecodings("227"))
        print(self.numDecodings("100"))
        # print(
        #     self.numDecodings(
        #         "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948"
        #     )
        # )
