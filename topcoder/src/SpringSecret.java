import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SpringSecret {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException 
	{
		// TODO Auto-generated method stub
		int no_of_test , i;
		int Y , Z;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String inputstring;
		
		no_of_test = Integer.parseInt(br.readLine());
		
		for(i=0;i<no_of_test;i++)
		{
			inputstring = br.readLine();
			Y = 0 ; Z = 0;
			for(int j=0;j<inputstring.length();j++)
			{
				if(inputstring.charAt(j) == 'S' && j!=inputstring.length()-1 && inputstring.charAt(j+1)=='S')
				{
					Y++;
				}
				else if(inputstring.charAt(j) == 'S' && j!=inputstring.length()-1 && inputstring.charAt(j+1)!='S' )
				{
					Z++;
				}
			}
			System.out.println("Case "+ (i+1) +": "+Y+" / "+Z);
		}
		
	}

}
