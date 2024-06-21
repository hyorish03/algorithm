
import java.util.Scanner;

public class Main {

	/*
	 * 문제 정의 
	 * 수열의 합이 100이 되도록 주여진 수열 중 2개의 원소를 뽑아 수열에서 제거해보자
	 * 순서 상관 X -> 조합 사용 (1, 2)를 뽑은거나 (2, 1)을 뽑는게 동일한 상황 
	 * 중복조합 X -> 원소를 뽑을 때 처리 필요 (1, 1) 이렇게 뽑으면 안 됨
	 * 시간제한 1초 -> 1억번 연산 가능, 9개 중 2개를 뽑는 9C2 = 36으로 완전탐색을 해도 널럴한 문제
	 * */
	
	
	static int arr[] = new int[10]; // 수열 담는 배열 
	static int ans[] = new int[10]; // 2개 뽑은걸 담는 배열 
	static boolean vis[] = new boolean[10];
	static int sum = 0; // 수열의 총 합 
	static boolean flag = false; // 답이 나오면 연산을 멈춤 
	
	public static void main(String[] args) {
		
		// 입력이 9개로 적기에 Scanner 
		Scanner sc = new Scanner(System.in);
		
		for(int i =0; i < 9; i++) {
			arr[i]=  sc.nextInt();
			sum += arr[i];
		}
		
		dfs(0, 0);
		sc.close();
	}
	
	private static void dfs(int cur, int cnt) {
		// 뽑은 2개의 원소가 
 		 if(cnt == 2){
 			 	// 총 수열의 합에서 두 원소의 합을 뺀 값이 100이라면 
		        if(sum - (ans[0]+ans[1]) == 100){
		            for(int i = 0; i < 9; i++){
		            	// 출력해줄껀데 두 원소는 제외하고 출력해줌 
		                if(arr[i] != ans[0] && arr[i] != ans[1]){
		                	System.out.println(arr[i]);
		                }
		            }
		            // 답 나왔으니 flag true 
		            flag = true;
		        }
		        return;
		    }
		    
		    for(int i = 0; i < 9; i++){
		    	// 중복으로 뽑으면 안되니 방문체크용 vis 배열 사용
		    	// 조합을 사용해야 하니 첫 번째로 뽑힌 요소보다 큰 값만 두 번째 요소로 뽑음 
		    	// (1, 2)이 뽑혔는데 또 (2, 1)이 뽑히는 것을 방지 
		        if(!vis[i] && cur <= arr[i]){
		            vis[i] = true;
		            ans[cnt] = arr[i];
		            dfs(arr[i],cnt+1);  
		            
		            // 답이 나오면 연산을 멈춤 -> 실제로 1번 테케에 이를 적용하면 36번 연산이 30번으로 줄어
		            if(flag){
		                break;
		            }
		            vis[i] = false;
		        }
		    }
	}

}
