import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class CodevitaScrambled 
{
	public static void main(String[] args) throws IOException 
	{
		// TODO Auto-generated method stub
		int key , i , j , wordcount , keysize;
		String paragraph;
		int [] S = new int [30];
		char [] word = new char [30];
		int [] charkey = new int [5];
		
		Scanner sc = new Scanner(System.in);
		key = sc.nextInt();
		
		j=0;
		keysize = 0;
		while(key>0)
		{
			charkey[j] = key%10;
			key/=10;
			keysize++;
			j++;
		}
		for(j=0;j<keysize/2;j++)
		{
			int temp;
			temp = charkey[keysize-1-j];
			charkey[keysize-1-j] = charkey[j];
			charkey[j] = temp;
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int ch;
		ch = br.read();
		System.out.println(ch);
		
		while(sc.hasNext())
		{
			boolean lastcharnonalphaflag = false;
			paragraph = sc.next();
			int fprev = 0 , fcurr = 0 , length;
			length = paragraph.length();
			if(!Character.isLetter(paragraph.charAt(length-1)))
			{
				lastcharnonalphaflag = true;
				length--;
			}
			for(i=0;i<length-2;i++)
			{
				S[i] = i;
			}
			for(i=1;i<length-1; i++)
			{
				word[i-1] = paragraph.charAt(i);
			}
			
			int sum;
			for(i=0;i<length-2;i++)
			{
				sum = fprev + S[i] + charkey[i%keysize];
				
				fcurr = sum%(length-2);
				
				int swap;
				swap = S[i];
				S[i] = S[fcurr];
				S[fcurr] = swap;
				
				fprev = fcurr;
			}
			
			System.out.print(paragraph.charAt(0));
			
			for(i=0;i<length-2;i++)
			{
				System.out.print(word[S[i]]);
			}
			
			if(length>1)
			{
				System.out.print(paragraph.charAt(length-1));
			}
			if(lastcharnonalphaflag)
			{
				System.out.print(paragraph.charAt(length));
			}
			if(sc.hasNext())
			{
				System.out.print(" ");
			}
		}
	}

}
