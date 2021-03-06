# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
#BFS , level order traversal
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        q,maxsum,maxlevel,level=[root],float('-inf'),0,0
        while q:
            level+=1
            sum=0
            for _ in range(len(q)):
                tmp=q[0]
                q=q[1:]
                sum+=tmp.val
                if tmp.left:
                    q.append(tmp.left)
                if tmp.right:
                    q.append(tmp.right)
            if maxsum<sum:
                maxsum,maxlevel=sum,level
        return maxlevel


#DFS
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        def dfs(root,level):
            if not root:
                return 
            if level==len(list):
                list.append(root.val)
            else:
                list[level]+=root.val
            dfs(root.left,level+1)
            dfs(root.right,level+1)
        list=[]
        dfs(root,0)
        return 1+list.index(max(list))
                