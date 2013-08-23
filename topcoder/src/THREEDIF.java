import java.math.BigInteger;
import java.util.Scanner;

public class THREEDIF 
{

	public static void main(String[] args) throws Exception
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String num;
		BigInteger num1 = null, num2 = null, num3 = null, temp = null, mul = null, total=null;
		
		int n,i;
		n = sc.nextInt();
		for(i=0; i<n; i++)
		{
			num = sc.next();
			num1 = new BigInteger(num);
			
			num = sc.next();
			num2 = new BigInteger(num);
			
			num = sc.next();
			num3 = new BigInteger(num);
			
			if(num1.compareTo(num2)<=0)
			{
				if(num1.compareTo(num3)<=0)
				{
					if(num2.compareTo(num3)>0)
					{
						temp = num2;
						num2 = num3;
						num3 = temp;
					}
				}
				else
				{
					temp = num3;
					num3 = num1;
					num1 = temp;
				}
			}
			else
			{
				if(num1.compareTo(num3)<=0)
				{
					temp = num2;
					num2 = num1;
					num1 = temp;
				}
				else
				{
					temp = num3;
					num3 = num1;
					num1 = temp;
					if(num2.compareTo(num3)>0)
					{
						temp = num3;
						num3 = num2;
						num2 = temp;
					}
				}
			}
			
			num2 = num2.subtract(new BigInteger("1"));
			num3 = num3.subtract(new BigInteger("2"));
			
			num1 = num1.mod(new BigInteger("1000000007"));
			num2 = num2.mod(new BigInteger("1000000007"));
			num3 = num3.mod(new BigInteger("1000000007"));
			
			mul = num1.multiply(num2);
			
			mul = mul.mod(new BigInteger("1000000007"));
			
			mul = mul.multiply(num3);
			
			total = mul.mod(new BigInteger("1000000007"));
			System.out.print(total+"\n");
			
		}
	}

}
