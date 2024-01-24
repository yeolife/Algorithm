import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	private static int n, ans = 1000000000;
	private static int[][] arr = new int[22][22];
	private static boolean[] cur = new boolean[22];
	
	private static void func(int k, int s0, int s1){
	    if(k == n){
	        ans = Math.min(ans, Math.abs(s0 - s1));
	        return;
	    }
	    int t0 = 0, t1 = 0;
	    for(int i = 0; i < k; i++){
	        if(cur[i]) t1 += arr[i][k];
	        else t0 += arr[i][k];
	    }
	    cur[k] = false;
	    func(k + 1, s0 + t0, s1);
	    cur[k] = true;
	    func(k + 1, s0, s1 + t1);
	}

	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
	        for(int j = 0; j < n; j++){
	        	int k = Integer.parseInt(st.nextToken());
	        	
	        	if(i > j) arr[j][i] += k;
	            else arr[i][j] += k;
	        }
		}
		
		func(0, 0, 0);
		
		System.out.print(ans);
	}
}