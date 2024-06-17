import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		// 입력도구: Scanner, BufferedReader(2배 빠름)
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		StringTokenizer tok = new StringTokenizer(s);
		int a = Integer.parseInt(tok.nextToken());
		int b = Integer.parseInt(tok.nextToken());
		
		System.out.println(a+b);
		
//		Scanner sc = new Scanner(System.in);
//		sc.close();
	}
}
