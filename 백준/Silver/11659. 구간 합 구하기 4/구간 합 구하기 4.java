import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(br.readLine(), " ");
		int n = Integer.parseInt(tok.nextToken());
		int tc = Integer.parseInt(tok.nextToken());
		StringTokenizer nums = new StringTokenizer(br.readLine(), " ");
		int arr[] = new int[n+2];
		int memo[] = new int[n+2];
		for(int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(nums.nextToken());
		}

		memo[0] = 0;
		for(int i = 0; i <= n; i++) {
			memo[i+1] = memo[i] + arr[i];
		}

		
		for(int i = 0; i < tc; i++) {
			StringTokenizer sten = new StringTokenizer(br.readLine(), " ");
			int st = Integer.parseInt(sten.nextToken());
			int en = Integer.parseInt(sten.nextToken());
			
			System.out.println(memo[en] - memo[st-1]);
		}
	}
}
