import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.StringTokenizer;

/*
 * 남: 스위치 번호가 자기가 받은 수의 배수 -> 스튀치의 상태를 바꿈 3을 받으면 3, 6을 바
 * 여: 받은 위치 번호 기준으로 대칭인 부분을 모두 바
 * */

public class Main {

	public static void main(String[] args) throws IOException {
		// 입력도구: Scanner, BufferedReader(2배 빠름)
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(br.readLine(), " ");
		int strLen = Integer.parseInt(tok.nextToken());
		int windowLen = Integer.parseInt(tok.nextToken());
		String STR = br.readLine();
		int answer = 0;
//		StringTokenizer strTok = new StringTokenizer(br.readLine(),"");
		
		
		StringTokenizer token = new StringTokenizer(br.readLine(), " ");
		int A = Integer.parseInt(token.nextToken());
		int C = Integer.parseInt(token.nextToken());
		int G = Integer.parseInt(token.nextToken());
		int T = Integer.parseInt(token.nextToken());
		
		Deque<Character> dq = new ArrayDeque<>();
		ArrayList<Character> lst = new ArrayList<>();
		for (int i = 0; i < STR.length(); i++) {
			lst.add(STR.charAt(i));
		}

		for (int i = 0; i < windowLen; i++) {
			dq.addLast(lst.get(i));
//			System.out.print(lst.get(i));
		}

//		
//		Deque<Character> testDQ = new ArrayDeque<>();
//		testDQ = dq;
		int cntA = 0, cntC = 0, cntG = 0, cntT = 0;
		for (char ch : dq) {
			switch (ch) {
			case 'A':
				cntA++;
				break;
			case 'C':
				cntC++;
				break;
			case 'G':
				cntG++;
				break;
			case 'T':
				cntT++;
				break;
			}
		}
		
		if(cntA >= A && cntC >= C && cntG >= G && cntT >= T) {
			answer++;
		}
		int idx = windowLen;
		while (idx < lst.size()) {
				switch (dq.getFirst()) {
				case 'A':
					cntA--;
					break;
				case 'C':
					cntC--;
					break;
				case 'G':
					cntG--;
					break;
				case 'T':
					cntT--;
					break;
				}
			if (idx < lst.size()) {
	                dq.removeFirst();
	                dq.addLast(lst.get(idx));
	          }
			switch (dq.getLast()) {
			case 'A':
				cntA++;
				break;
			case 'C':
				cntC++;
				break;
			case 'G':
				cntG++;
				break;
			case 'T':
				cntT++;
				break;
			}
			if(cntA >= A && cntC >= C && cntG >= G && cntT >= T) {
				answer++;
			}
			idx++;

		}

		System.out.println(answer);

	}

}


