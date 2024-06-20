import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static int nums;
	static int calc[] = new int[4];
	static ArrayList<Integer> temp = new ArrayList<Integer>();
	static ArrayList<Integer> ls = new ArrayList<Integer>();

	static int mmin = 1000000001;
	static int mmax = -1000000001;
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		nums = Integer.parseInt(br.readLine());
		StringTokenizer tok = new StringTokenizer(br.readLine(), " ");
		
		for(int i = 0; i < nums; i++) {
			int num = Integer.parseInt(tok.nextToken());
			ls.add(num);
		}
		
		StringTokenizer token = new StringTokenizer(br.readLine(), " ");
		for(int i = 0; i < 4; i++){
			calc[i] = Integer.parseInt(token.nextToken());
		}
		
		dfs(ls.get(0), 1 );
		
		System.out.println(mmax + "\n" + mmin);
	}
	
	static void dfs(int result, int idx) {
		if(idx == nums)
	    {
	        if(result > mmax)
	            mmax = result;
	        if(result < mmin)
	            mmin = result;
	        return;
	    }
		
	    for(int i = 0; i < 4; i++)
	    {
	        if(calc[i] > 0)
	        {
	            calc[i]--;
	            if(i == 0)
	                dfs(result + ls.get(idx), idx+1);
	            else if(i == 1)
	                dfs(result - ls.get(idx), idx+1);
	            else if(i == 2)
	                dfs(result *ls.get(idx), idx+1);
	            else
	                dfs(result / ls.get(idx), idx+1);
	            calc[i]++;
	        }
	    }
	    return;
	}

}
