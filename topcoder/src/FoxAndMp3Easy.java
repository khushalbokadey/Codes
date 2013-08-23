import java.util.*;
import java.util.Collections;

import javax.swing.text.AbstractDocument.Content;

public class FoxAndMp3Easy {

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		String result[] = null;
		result = playList(10);
		for(int i=0;i<10;i++)
		{
			System.out.println(result[i]);
		}
	}
	
	public static String[] playList(int n)
	{
		String [] strresult = new String[50];
		List<String> content = new ArrayList<String>();
		int i, val;
		for(i=0;i<n;i++)
		{
			content.add(Integer.toString(i+1));
		}
		Collections.sort(content);
		val = n;
		if(n>50)
		{
			val = 50;
		}
		for(i=0;i<val;i++)
		{
			strresult[i] = content.get(i)+".mp3";
		}
		String [] result = new String[val];
		for(i=0;i<val;i++)
		{
			result[i] = strresult[i];
		}
		return result;
	}

}
