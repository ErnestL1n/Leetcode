/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 //BFS
func levelOrder(root *TreeNode) [][]int {
    var q []*TreeNode
    var res [][]int
    if root==nil{
        return res
    }
    q=append(q,root)
    for len(q)>0{
        levelNum:=len(q)
        var tmp []int
        for i:=0;i<levelNum;i+=1{
            if q[0].Left!=nil{
                q=append(q,q[0].Left)
            }
            if q[0].Right!=nil{
                q=append(q,q[0].Right)
            }
            tmp=append(tmp,q[0].Val)
            q=q[1:]
        }
        res=append(res,tmp)
    }
    return res
}

//DFS
func levelOrder(root *TreeNode) [][]int {
    var res [][]int
    dfs(&res,root,0)
    return res
}
func dfs(res *[][]int,root *TreeNode,depth int) {
    if root==nil{
        return 
    }
    if len(*res)==depth{
        (*res)=append(*res,[]int{})
    }
    (*res)[depth]=append((*res)[depth],root.Val)
    dfs(res,root.Left,depth+1)
    dfs(res,root.Right,depth+1)
}