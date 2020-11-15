class Solution:
    def __init__(self):
        self.move = [
            (4, 6),
            (1, 8),
            (7, 9),
            (4, 8),
            (3, 9, 0),
            (5,),
            (1, 7, 0),
            (2, 6),
            (1, 3),
            (2, 4),
        ]
        self.memo = [[0 for i in range(10)] for i in range(5001)]
        # memo[steps_left][number]
        self.memo[1] = [1 for _ in range(10)]
        # self.memo[2] = [2, 2, 2, 2, 3, 0, 3, 2, 2, 2]

    def knightDialer(self, N: int) -> int:
        for i in range(2, N + 1):
            self.memo[i] = [
                sum([self.memo[i - 1][dest] for dest in self.move[pos]])
                for pos in range(10)
            ]

        return sum(self.memo[N])
