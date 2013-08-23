
public class Suminator {

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		int [] arr = {100, 200, 300, 0, 100, -1};
		System.out.println(findMissing(arr, 600));

	}
	
	public static int findMissing(int[] program, int wantedResult)
	{
		int X = -3 , top, i , len = 0;
		int [] newarray = new int[50];
		
		top=0;
		for(i=0;i<program.length;i++)
		{
			if(program[i]==-1)
			{
				newarray[top] = -2;
			}
			else if(program[i]==0)
			{
				if(newarray[top]!=-2 && newarray[top-1]!=-2)
				{
					int temp;
					temp = newarray[top-1] + newarray[top-2];
					newarray[top-2] = temp;
					top--;
					top--;
					len--;
				}
			}
			else
			{
				newarray[top] = program[i];
			}
			top++;
			len++;
		}
		len--;
		if(newarray[len-1]==-2 || newarray[len-2]==-2)
		{
			if(newarray[len-1]==-2)
			{
				X = wantedResult - newarray[len-2];
			}
			else
			{
				X = wantedResult - newarray[len-1];
			}
		}
		if( (newarray[len-1]==-2 || newarray[len-2]==-2)&& len>=3 && (wantedResult == newarray[len-2] + newarray[len-3]))
		{
			X = 0;
		}
		else if(X==-3)
		{
			X=-1;
		}
		return X;
	}

}
