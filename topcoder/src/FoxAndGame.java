
public class FoxAndGame {

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		String[] str = {"---",
				 "o--",
				 "oo-",
				 "ooo",
				 "ooo",
				 "oo-",
				 "o--",
				 "---"};
		System.out.println(countStars(str));

	}
	
	public static int countStars(String[] result)
	{
		int len, total, i,j;
		
		len = result.length;
		
		total = 0;
		for(i=0;i<len;i++)
		{
			for(j=0;j<3;j++)
			{
				if(result[i].charAt(j)=='o')
				{
					total++;
				}
			}
		}
		
		return total;
	}

}
