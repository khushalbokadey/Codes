import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;


public class Fileioop {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException 
	{
		// TODO Auto-generated method stub
		FileInputStream fin;
		FileOutputStream fout = new FileOutputStream(args[1]);
		fin = new FileInputStream(args[0]);
		int i;
		
		do
		{
			i = fin.read();
			if(i!=-1)
			{
				fout.write((char)i);
			}
		}while(i!=-1);

	}

}
