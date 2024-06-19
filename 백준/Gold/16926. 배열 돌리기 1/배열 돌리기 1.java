import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
	static int x, y;
	static int [][]Board = new int[301][301];
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer tok = new StringTokenizer(br.readLine(), " ");
		y = Integer.parseInt(tok.nextToken());
		x = Integer.parseInt(tok.nextToken());
		int rotate = Integer.parseInt(tok.nextToken());
		
		
		for(int i = 0; i < y; i++) {
			StringTokenizer token = new StringTokenizer(br.readLine(), " ");
			for(int j = 0; j < x; j++) {
				Board[i][j] = Integer.parseInt(token.nextToken());
			}
		}
		
		int min = Math.min(y, x);
		for(int i = 0; i < rotate; i++) {
			rotate(min/2);
		}
		
		for(int i = 0; i < y; i++) {
			for(int j = 0; j < x; j++) {
				System.out.print(Board[i][j]+" ");
			} System.out.println();
		}
	}
	
	static void rotate(int box) {
		for(int i=0; i<box; i++){  
			int leftUp= Board[i][i];
			int leftDown = Board[y-1-i][i];
			int rightUp = Board[i][x-1-i];
			int rightDown = Board[y-i-1][x-i-1];
//			System.out.println(leftUp + " " + leftDown+ " " + rightUp + " " + rightDown);

			
			// 왼쪽
			for(int j = y-2-i; j >= i ; j--) {
				Board[j+1][i] = Board[j][i];
			}
//			
//			System.out.println("++++++왼쪽회전++++++");
//			for(int k = 0; k < y; k++) {
//				for(int t = 0; t < x; t++) {
//					System.out.print(Board[k][t]+" ");
//				} System.out.println();
//			}
			
//			Board[i][i] = leftDown;
			// 아래
			for(int j = x-i-1; j > i ; j--) {
				Board[y-1-i][j] = Board[y-1-i][j-1];
			}
//			Board[y-i-1][i+1] = leftDown;
//			System.out.println("++++++아회전++++++");
//			for(int k = 0; k < y; k++) {
//				for(int t = 0; t < x; t++) {
//					System.out.print(Board[k][t]+" ");
//				} System.out.println();
//			}
			// 오른쪽 
			for(int j = i; j < y-i-1; j++) {
				Board[j][x-i-1] = Board[j+1][x-i-1];
			}
//			System.out.println("+++++오른쪽회전++++++");
//			for(int k = 0; k < y; k++) {
//				for(int t = 0; t < x; t++) {
//					System.out.print(Board[k][t]+" ");
//				} System.out.println();
//			}
//			Board[i][x-i-1] = rightUp;
			// 위 
			for(int j = i; j < x-2-i; j++) {
				Board[i][j] = Board[i][j+1];
			}
//			System.out.println("+++++위쪽회전++++++");
//			for(int k = 0; k < y; k++) {
//				for(int t = 0; t < x; t++) {
//					System.out.print(Board[k][t]+" ");
//				} System.out.println();
//			}
//			System.out.println("+++++최++++++");

			Board[i][x-i-2] = rightUp;
			Board[y-i-2][x-i-1] = rightDown;
			Board[y-1-i][i+1] = leftDown;
			

	    }
	}
	
}
/*
4 4 2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
 * */

//1  2  3  3  4

//7  8  3  9  10

//13 14 3  15 16

//19 20 3  21 22

//25 26 3  27 28


