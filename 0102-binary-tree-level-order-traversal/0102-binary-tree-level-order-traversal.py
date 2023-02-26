# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        queue = deque()
        res = []
        
        if root:
            queue.append(root)
            
                    
        while len(queue) > 0:
            lvl = []
            for i in range(len(queue)):
                root = queue.popleft()
                lvl.append(root.val)
                if root.left:
                    queue.append(root.left)
                if root.right:
                    queue.append(root.right)
            res.append(lvl)
        
        return res
                
            