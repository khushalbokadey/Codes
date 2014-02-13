import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;


public class Spclmultiple {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		int i, j, k, T, N;
		boolean flag;
		BufferedReader inp = new BufferedReader (new InputStreamReader(System.in));
		BigInteger numbers[] = new BigInteger [25030];
		numbers[0] = new BigInteger("0");
	    numbers[1] = new BigInteger("9");
	    j = 0;
	    i = 2;
	    while (i<10000) {
	        for (k = (int) Math.pow(2,j); k< Math.pow(2,j+1); k++) {
	            numbers[i++] = numbers[k].multiply(new BigInteger("10")).add(new BigInteger("0"));
	            numbers[i++] = numbers[k].multiply(new BigInteger("10")).add(new BigInteger("9"));
	        }
	        j++;
	    }
	    T= Integer.parseInt(inp.readLine());
	    while (T != 0) {
		    N= Integer.parseInt(inp.readLine());
		    flag = false;
		    for (i=1; i<10000; i++) {
		    	if (numbers[i].mod(BigInteger.valueOf(N)).equals(new BigInteger("0"))) {
		    		System.out.println(numbers[i]);
		    		flag = true;
		    		break;
		    	}
		    }
		    if (!flag) {
		    	System.out.println("0");
		    }
		    T--;
	    }
	}

}
