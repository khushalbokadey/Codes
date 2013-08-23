import java.io.*;
import java.text.DecimalFormat;
import java.util.Scanner;


public class CodevitaTranspose
{

	public static void main(String[] args) throws Exception 
	{
		// TODO Auto-generated method stub
		String filename;
		Scanner sc = new Scanner(System.in);
		
		filename = sc.next();
		Scanner scanner = new Scanner(new File(filename));
		
		int rows = 0 , columns = 0;
		int i , j;
		boolean errorflag = false;
		float [][] arr = new float [100][100];
		float [][] transpose = new float [100][100];
		
		while(scanner.hasNextLine())
		{
		    j=0;
		    Scanner colReader = new Scanner(scanner.nextLine());
		    while(colReader.hasNextFloat())
		    {
		    	if(rows==0 || columns==0)
		        {
		    		if(colReader.hasNextFloat())
		    		{
		    			columns++;
		    		}
		        }
		        arr[rows][j++] = colReader.nextFloat();
		    }
		    if(rows!=0 && columns!=j)
		    {
		    	errorflag = true;
		    }
		    if(j==0)
		    {
		    	rows--;
		    }
		    rows++;
		}
		if(errorflag || rows==0 || columns==0)
		{
			System.out.println("Invalid Input");
		}
		else
		{
			System.out.println("Size before transpose is "+rows+"x"+columns);
			for(i=0;i<rows;i++)
			{
				for(j=0;j<columns;j++)
				{
					transpose[j][i] = arr[i][j];
				}
			}
			DecimalFormat df = new DecimalFormat("0.000");
			for(i=0;i<columns;i++)
			{
				for(j=0;j<rows;j++)
				{
					System.out.print(2.30+ df.format(transpose[i][j]));
					if(j!=rows-1)
					{
						System.out.print(" ");
					}
				}
				System.out.println();
			}
			System.out.println("Size after transpose is "+columns+"x"+rows);
		}
	}

}
