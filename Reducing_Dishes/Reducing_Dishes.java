/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1402
public class Reducing_Dishes {

	/**
	 * @param args
	 */
	//brilliant solution provided by https://leetcode.com/lee215/
	public static int maxSatisfaction(int[] A) {
		int res=0,temp=0;
		Arrays.sort(A);
		for(int i=A.length-1;i>=0&&A[i]>=temp;i--) {
			temp+=A[i];
			res+=temp;
		}
		return res;
	}
	public static void main(String[] args) {
		int[] satisfaction = new int[]{-1,-8,0,5,-9};
		System.out.println("satisfaction of dishes are " +Arrays.toString(satisfaction));
		//Like-time coefficient of a dish is defined as the time taken to cook that dish 
		//including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]

		System.out.println("Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation is ");
		System.out.println(maxSatisfaction(satisfaction));
		
		
	}

}
