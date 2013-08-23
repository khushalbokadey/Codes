import java.util.*;
public class codevitaISBN 
{

	public static void main(String[] args) 
	{
		String arr = new String();
		int i, flag ,flag1;
		int sum , index=0 , reqd=0;
	    Scanner sc = new Scanner(System.in);
	    arr=sc.next();
	    flag = 1;
	    for(i=0;i<9;i++)
	    {
	        if(!(arr.charAt(i)>=48 && arr.charAt(i)<=57) && arr.charAt(i)!='?')
	        {
	            flag = 0;
	            break;
	        }
	    }
	    if(!(arr.charAt(9)>=48 && arr.charAt(9)<=57) && arr.charAt(9)!='X' && arr.charAt(9)!='?')
	    {
	        flag = 0;
	    }
	    if(flag!=0)
	    {
	        sum = 0;
	        for(i=0;i<10;i++)
	        {
	            if(arr.charAt(i)>=48 && arr.charAt(i)<=57)
	            {
	                sum += (10-i)*(arr.charAt(i)-48);
	            }
	            else if(arr.charAt(i)=='?')
	            {
	                index = 10-i;
	            }
	            else if(arr.charAt(i)=='X')
	            {
	                sum += 10;
	            }
	        }
	        flag1 = 0;
	        int next , diff;
	        diff = 11-(sum%11);
	        next = sum+diff;
	        for(int j=0;j<10;j++)
	        {
	        	reqd = next - sum;
	        	if(reqd%index==0)
	        	{
	        		flag1 = 1;
	        		break;
	        	}
	        	next+=11;
	        }
	        if(flag1==1)
	        {
	        	if(reqd/index == 10 && index == 1)
	        	{
	        		System.out.println('X');
	        	}
	        	else if(reqd/index == 10 && index != 1)
	        	{
	        		System.out.println("NO SOLUTION POSSIBLE");
	        	}
	        	else
	        	{
	        		System.out.println(reqd/index);
	        	}
	        }
	        else
	        {
	           System.out.println("NO SOLUTION POSSIBLE");
	        }
	    }
	    else
	    {
	    	System.out.println("INVALID INPUT");
	    }

	}

}

