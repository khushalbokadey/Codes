import java.util.Scanner;
import java.math.BigInteger;

public class Main
{

	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		int no_of_test , n;
		
		BigInteger answer = BigInteger.valueOf(0) , num;
		
		Scanner sc = new Scanner (System.in);
		no_of_test = sc.nextInt();
		
		for(int i = 0;i<no_of_test;i++)
		{
			n = sc.nextInt();
			answer = BigInteger.valueOf(1);
			while(n>1)
			{
				answer = answer.multiply(BigInteger.valueOf(n));
				n--;
			}
			System.out.println(answer);
		}
	}

}
