
public class TheBrickTowerEasyDivTwo {

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		System.out.println(find(47,47,47,47));
	}

	public static int find(int redCount, int redHeight, int blueCount, int blueHeight)
	{
		int i , j , count , k;
		int [] sum = new int[10000];
		
		count=0;
		k=0;
		if(redCount<=blueCount)
		{
			for(i=1;i<=redCount;i++)
			{
				int temp;
				temp = i*redHeight + i*blueHeight;
				
				if(search(temp, sum))
				{
					count++;
					sum[k] = temp;
					k++;
				}
				if(i!=blueCount)
				{
					temp = i*redHeight + (i+1)*blueHeight;
					if(search(temp, sum))
					{
						count++;
						sum[k] = temp;
						k++;
					}
				}
				if(i!=redCount)
				{
					temp = (i+1)*redHeight + i*blueHeight;
					if(search(temp, sum))
					{
						count++;
						sum[k] = temp;
						k++;
					}
				}
			}
		}
		else
		{
			for(i=1;i<=blueCount;i++)
			{
				int temp;
				temp = i*redHeight + i*blueHeight;
				
				if(search(temp, sum))
				{
					count++;
					sum[k] = temp;
					k++;
				}
				if(i!=redCount)
				{
					temp = (i+1)*redHeight + i*blueHeight;
					if(search(temp, sum))
					{
						count++;
						sum[k] = temp;
						k++;
					}
				}
				if(i!=blueCount)
				{
					temp = i*redHeight + (i+1)*blueHeight;
					if(search(temp, sum))
					{
						count++;
						sum[k] = temp;
						k++;
					}
				}
			}
		}
		if(redHeight==blueHeight)
		{
			count++;
		}
		else
		{
			count+=2;
		}
		return count;
	}
	
	public static boolean search(int number , int[] arr)
	{
		int i;
		for(i=0;i<arr.length;i++)
		{
			if(arr[i] == number)
			{
				return false;
			}
		}
		
		return true;
	}
}
