
public class Sortedarrayrotate {

	/**
	 * @param args
	 */
	
	static int smallestindexpos;
	
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		int [] numbers = {5,6,7,7,8,9,9,9,9,1,1,1,1,1,2,3,4};
		
		binarySearch(numbers , 0 , numbers.length , 0);
		System.out.println(smallestindexpos%numbers.length);
	}
	static void binarySearch(int[] search , int start , int end , int index) 
	{
		int length = end-start;
		if(length==1)
		{
			return;
		}
		if(search[index + length/2-1] > search[index + length/2])
		{
			smallestindexpos = index + length/2;
		}
		else if(search[index + length/2] > search[index + length/2+1])
		{
			smallestindexpos = index + length/2 + 1;
		}
		else if (search[index + length/2-1] < search[index + length/2] && length>3 && search[index + length/2-2] <= search[index + length/2-1])
		{
			binarySearch(search , index+length/2 , end , index + length/2);
		}
		else if(search[index + length/2-2] > search[index + length/2-1])
		{
			smallestindexpos = index + length/2 - 1;
		}
		else if (search[index + length/2-1] == search[index + length/2]) 
		{
			binarySearch(search , 0 , length/2 , 0);
			binarySearch(search , index+length/2 , end , index + length/2);
		}
	}

}
