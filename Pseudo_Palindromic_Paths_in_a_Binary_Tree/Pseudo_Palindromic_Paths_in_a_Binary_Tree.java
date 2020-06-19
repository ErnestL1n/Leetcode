/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1457
class TreeNode{
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int value){
		this.val=value;
	}
	TreeNode(int value,TreeNode leftchild,TreeNode rightchild){
		this.val=value;
		this.left=leftchild;
		this.right=rightchild;
	}
}
public class Pseudo_Palindromic_Paths_in_a_Binary_Tree {

	/**
	 * @param args
	 */
	public static TreeNode BuildTree(Integer[] nodes) {
		if(nodes==null&&nodes.length==0)return null;
		Queue<TreeNode> treenodequeue=new LinkedList<>();
		Queue<Integer> integerqueue=new LinkedList<>();
		TreeNode root=new TreeNode(nodes[0]);
		treenodequeue.offer(root);
		for(int i=1;i<nodes.length;i++)integerqueue.offer(nodes[i]);
		while(!integerqueue.isEmpty()) {
			Integer leftvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			Integer rightvalue=integerqueue.isEmpty()?null:integerqueue.poll();
			TreeNode current=treenodequeue.poll();
			if(leftvalue!=null) {
				TreeNode leftchild=new TreeNode(leftvalue);
				current.left=leftchild;
				treenodequeue.offer(leftchild);
			}
			if(rightvalue!=null) {
				TreeNode rightchild=new TreeNode(rightvalue);
				current.right=rightchild;
				treenodequeue.offer(rightchild);
			}
		}
		return root;
	}
	
	public static int getTreeSize(TreeNode root) {
		if(root==null)return 0;
		return 1+getTreeSize(root.left)+getTreeSize(root.right);
	}
	
	public static void printTree(TreeNode root) {
		if(root==null)return;
		int treesize=getTreeSize(root);
		Queue<TreeNode> treenodequeue=new LinkedList<>();
	    treenodequeue.offer(root);
	    System.out.println("I am root , my value is "+root.val);
	    treesize--;
	    while(treesize!=0) {
	    	TreeNode current=treenodequeue.poll();
	    	TreeNode leftchild=current.left;
	    	TreeNode rightchild=current.right;
	    	if(leftchild!=null) {
	    		treenodequeue.offer(leftchild);
	    		System.out.println("I am  leftchild of "+current.val+" my value is "+leftchild.val);
	    		treesize--;
	    	}
	    	if(rightchild!=null) {
	    		treenodequeue.offer(rightchild);
	    		System.out.println("I am rightchild of "+current.val+" my value is "+rightchild.val);
	    		treesize--;
	    	}
	    }
	}
	
	//Method 1:Use Array :It runs 8ms, memory usage:57.9 MB in Leetcode
	private static int count=0;
	public static int pseudoPalindromicPathsMethod1 (TreeNode root) {
		//constraint:digit:1~9
		find(root,new int[10]);
		return count;
	}
	public static void find(TreeNode root,int[] freq) {
		if(root==null)return;
		freq[root.val]++;
		//leaf nodes
		if(root.left==null&&root.right==null) {
			int flag=0;
			for(int i=1;i<=9;i++)
				if(freq[i]%2!=0)flag++;
			if(flag<=1)count++;
		}
		find(root.left,freq);
		find(root.right,freq);
		//minus freq back to the branch node
		freq[root.val]--;
	}
	public static void main(String[] args) {
		Integer[] nodes=new Integer[] {2,3,1,3,1,null,1};
		TreeNode root=BuildTree(nodes);
		printTree(root);
		System.out.println("Number of pseudo-palindromic paths going from the root node to leaf nodes is "+pseudoPalindromicPathsMethod1(root));
		
	}

}
