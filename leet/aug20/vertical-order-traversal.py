#!/usr/bin/env python3

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def from_list(self, lst):
        lst = lst.insert(0, 0)
        return self.build_tree(lst, 1)

    def build_tree(self, lst, pos):
        if pos >= len(lst):
            return None
        else:
            return TreeNode(
                lst[pos], build_tree(lst, 2 * pos), build_tree(lst, 2 * pos + 1)
            )


class Solution:
    def verticalTraversal(self, root):
        self.ans = [[]]
        self.displacement = 0
        self.travel(root, 0)
        ans = [[tup[1] for tup in list_of_tup] for list_of_tup in self.ans]
        return ans

    def travel(self, tree, x_coord, y_coord) -> None:
        if not tree:
            return
        # if x_coord + displacement < 0 means need prepend
        #   then displacement +=1
        if x_coord + self.displacement < 0:
            self.displacement += 1
            self.ans.insert(0, [])
        elif x_coord + self.displacement >= len(self.ans):
            self.ans.append([])
        # put root value in tree in ans[x_coord+displacement] with the weight y_coord
        self.ans[x_coord + self.displacement].append((y_coord, tree.val))
        # travel left (tree.left, x_coord-1)
        travel(tree.left, x_coord - 1, y_coord - 1)
        # travel right (tree.right, x_coord+1)
        travel(tree.right, x_coord + 1, y_coord - 1)


s = Solution()
t = TreeNode()
ans = s.verticalTraversal(t.from_list([1, 2, 3, 4, 5, 6, 7]))
print(ans)
