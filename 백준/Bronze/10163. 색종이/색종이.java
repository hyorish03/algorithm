import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int [][]Board = new int[1002][1002];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		int minX = 10001;
		int minY = 10001;
		int maxX = -1;
		int maxY = -1;
		for(int i = 1; i <= tc; i++) {
			StringTokenizer tok = new StringTokenizer(br.readLine(), " ");
			int x = Integer.parseInt(tok.nextToken());
			int y = Integer.parseInt(tok.nextToken());
			int w = Integer.parseInt(tok.nextToken());
			int h = Integer.parseInt(tok.nextToken());
			
			minX = Math.min(minX, x);
			minY = Math.min(minY, y);
			maxY = Math.max(maxX, x+w);
			maxX = Math.max(maxY, y+h);
			for(int j = x; j < w+x; j++) {
				for(int k = y; k < h+y; k++) {
					Board[j][k] = i;
				}
			}
		}

		
		for(int idx = 1; idx <= tc; idx++) {
			int cnt = 0;
			for(int i = 0; i <= 1001; i++) {
				for(int j = 0; j <= 1001; j++) {
					if(Board[i][j] == idx) {
						cnt++;
					}
				}
			}
			System.out.println(cnt);
		}
	
	}
}
