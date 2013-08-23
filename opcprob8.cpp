#include<iostream>
using namespace std;

public class LeaguePicks {

	public int[] returnPicks(int pos , int frnd , int pick )
	{
		int i=0 , j=0;
		String str = new String();
		str ="";
	/*	ret[i] = frnd*j + pos ; */
		str = str + (char)(frnd*j + pos) ;
		i++;
		j=2;
		while ((frnd*j - pos ) < pick)
		{

			//ret[i] = frnd*j - pos +1;
			str = str + (char)(frnd*j - pos +1);
			i++;
			//ret[i] = frnd*j + pos ;
			str = str + (char)(frnd*j +pos);
			i++;
			j++;
			j++;
		}
		int ret[] = new int [str.length()];
		for (i=0 ; i < str.length() ; i++)
		{
			ret[i] = (int)(str.charAt(i));
		}
		return ret;
	}

}
