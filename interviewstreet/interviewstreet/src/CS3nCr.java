import java.math.BigInteger;
import java.util.Scanner;


public class CS3nCr 
{

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		int no_of_test, i;

		long n = 0 , r = 0;
		BigInteger N, R, NCR;
		
		no_of_test = sc.nextInt();
		
		for(i=0;i<no_of_test;i++)
		{
			n = sc.nextLong();
			r = sc.nextLong();
			
			N = BigInteger.valueOf(n);
			R = BigInteger.valueOf(r);
			
			NCR = nCr(N, R);
			System.out.println(NCR);
		}
		
		
		

	}

	public static BigInteger nCr(BigInteger n, BigInteger r)
	{
	    if ( n.subtract(r).compareTo(r)<0 )
	        return nCr2( n, n.subtract(r) );
	    else
	        return nCr2( n, r );

	}
	public static BigInteger nCr2(BigInteger n, BigInteger r)
	{
	    if ( r.equals(0) )
	    {
	    	BigInteger retval;
	    	retval = BigInteger.valueOf(1);
	        return retval;
	    }
	    else
	    {
	    	BigInteger retval;
	    	retval = BigInteger.valueOf(1);
	    	BigInteger newN, newR;
	    	newN = n.subtract(retval);
	    	newR = r.subtract(retval);
	        return nCr2( newN, newR ).multiply(n.divide(r));
	    }
	}
	
}
