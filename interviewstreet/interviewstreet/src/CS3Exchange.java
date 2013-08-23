import java.math.BigInteger;
import java.nio.ByteBuffer;
import java.nio.IntBuffer;
import java.util.Scanner;
import java.util.zip.Adler32;


public class CS3Exchange 
{

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub

		System.out.println(test());
		Scanner sc = new Scanner(System.in);
		
		int no_of_perm, i, j;
		int [] K = new int[102];
		int [] output = new int[102];
		int [] temp = new int[102];
		
		String matrix[] = new String [102];

		
	    no_of_perm = sc.nextInt();

	    for(i=0;i<no_of_perm;i++)
	    {
	        K[i] = sc.nextInt();
	        output[i] = K[i];
	    }


	    for(i=0;i<no_of_perm;i++)
	    {
	        matrix[i] = sc.next();
	    }

	    for(i=0;i<no_of_perm;i++)
	    {
	        for(j=0;j<no_of_perm;j++)
	        {
	            if(matrix[i].charAt(j)=='Y')
	            {
	                for(int k =0;k<no_of_perm;k++)
	                {
	                    temp[k] = output[k];
	                }
	                temp[i] = output[j];
	                temp[j] = output[i];
	                if(issmall(output,temp, no_of_perm))
	                {
	                    for(int k =0;k<no_of_perm;k++)
	                    {
	                        output[k] = temp[k];
	                    }
	                }
	            }
	        }
	    }
	    
	    for(i=0;i<no_of_perm;i++)
	    {
	        System.out.print(output[i] + " ");
	    }
		
	}
	public static boolean test()
	{
		System.out.println("Asf");
		return false;
	}
	public static boolean issmall(int output[] , int temp[], int size)
	{
	    int i, outputlen, templen;
	    boolean flag = true;
	    
	    
	    String outputstr;
	    String tempstr;

	    BigInteger outputval, tempval;
	    outputval = BigInteger.valueOf(0);
	    tempval = BigInteger.valueOf(0);
	    long multiplier, adder1;
	    BigInteger multi, adder;
	    for(i=0;i<size;i++)
	    {
	    	outputstr = Integer.toString(output[i]);
	    	outputlen = outputstr.length();
	    	multiplier = (long) Math.pow(10, outputlen);
	    	multi = BigInteger.valueOf(multiplier);
	    	adder = BigInteger.valueOf(Long.parseLong(outputstr));
	    	outputval = outputval.multiply(multi);
	    	outputval = outputval.add(adder);
	    
	    	
	    	tempstr = Integer.toString(temp[i]);
	    	templen = tempstr.length();
	    	multiplier = (long) Math.pow(10, templen);
	    	multi = BigInteger.valueOf(multiplier);
	    	tempval = tempval.multiply(multi);
	    	adder = BigInteger.valueOf(Long.parseLong(tempstr));
	    	tempval = tempval.add(adder);
	    }
	    
	    
	    if(tempval.compareTo(outputval)>0)
	    {
	    	flag = false;
	    }

	    return flag;
	}


}
