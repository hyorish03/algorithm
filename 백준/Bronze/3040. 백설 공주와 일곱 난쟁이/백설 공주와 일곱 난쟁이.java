import java.text.DateFormatSymbols;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;
import java.util.Vector;

import org.w3c.dom.ls.LSException;

public class Main {

	static int arr[] = new int[10];
	static int ans[] = new int[10];

	static Stack<Integer> ls =new Stack<>(); 
	static boolean vis[] = new boolean[10];
	static int sum = 0;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		for(int i =0; i < 9; i++) {
			arr[i]=  sc.nextInt();
			sum += arr[i];
		}
		
		dfs(0, 0);
	}
	
	private static void dfs(int cur, int cnt) {
		 if(cnt == 2){
//			 System.out.println("HI");
//			 System.out.println(ans[0] +" "+ ans[1] );
		        if(sum - (ans[0]+ans[1]) == 100){
		            for(int i = 0; i < 9; i++){
		                if(arr[i] != ans[0] && arr[i] != ans[1]){
		                	System.out.println(arr[i]);
		                }
		            }
		        }
		        return;
		    }
		    
		    for(int i = 0; i < 9; i++){
		        if(!vis[i] && cur <= arr[i]){
		            vis[i] = true;
		            ans[cnt] = arr[i];
		            dfs(arr[i],cnt+1);       
		            vis[i] = false;
		        }
		    }
	}

}
