import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.Scanner;


public class Amdocsocenicwars {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException 
	{
		// TODO Auto-generated method stub
		Scanner inputfile = new Scanner (new File(args[0]));
		
		FileOutputStream outputfile = new FileOutputStream(args[1]);
		
		String attack = null;
		int no_of_attack;
		
		do
		{
			no_of_attack = inputfile.nextInt();
			for(int i = 0 ;i < no_of_attack ; i++)
			{
				attack = inputfile.next();
				System.out.println(attack);
			}
			attack = inputfile.next();
		}while(attack.equals("0"));
	}
}
