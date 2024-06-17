import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
 * 남: 스위치 번호가 자기가 받은 수의 배수 -> 스튀치의 상태를 바꿈 3을 받으면 3, 6을 바
 * 여: 받은 위치 번호 기준으로 대칭인 부분을 모두 바
 * */

public class Main {
	
	private static void Change(ArrayList<Integer> lst, int j) {
		// TODO Auto-generated method stub
		int temp = (int) lst.get(j);
		if(temp == 1) {
			lst.set(j, 0);
		} else {
			lst.set(j, 1);
		}
	}
	
	public static void main(String[] args) throws IOException {
		// 입력도구: Scanner, BufferedReader(2배 빠름)
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		ArrayList<Integer> lst = new ArrayList<Integer>(); 
	
		StringTokenizer tok = new StringTokenizer(br.readLine()," ");
		lst.add(9);

		for(int i = 0; i < n; i++) {
			int a = Integer.parseInt(tok.nextToken());
			lst.add(a);
		}
		
		int m = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < m; i++) {
			StringTokenizer token = new StringTokenizer(br.readLine()," ");
			int gender = Integer.parseInt(token.nextToken());
			int idx = Integer.parseInt(token.nextToken());
			
			if(gender == 1) {
				for(int j = 1; j < lst.size(); j++) {
					if(j % idx == 0 && j != 0) {
						Change(lst, j);
					}
				}
			} else {
				int temp=lst.get(idx);
				if(temp == 1) {
				lst.set(idx, 0);
				} else {
					lst.set(idx, 1);

				}
				int left = idx-1;
				int right = idx+1;
				while(left > 0 && right < lst.size()) {
					if(lst.get(left) != lst.get(right)) break;
					Change(lst, left);
					Change(lst, right);
					left--;
					right++;
					
				}
			}
		}
		
		for(int j = 1; j < lst.size(); j++) {
			System.out.print(lst.get(j) + " ");
			if(j % 20 == 0) {
				System.out.print('\n');
			}
		} 

	}

	
}
