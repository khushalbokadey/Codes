import javax.swing.Spring;

public class PikachuEasy {

	public static void main(String[] args)
	{


		int k=0;
		String S = new String("ilogic");
		int l=S.length();

		String W=new String(" ");

		String W2=new String(" ");
		int flag = 0;
		int alt = 0;
		for(int j=l-1;j>=0;j--)
		{

			String  pal=S.substring(0,j);


			for(k=(pal.length())-1;k>=0;k--)
			{char wc=pal.charAt(k);
			W=W+wc;
			}
			W=W.trim();

			if(W.equals(pal))
			{
				flag=1;
				alt=(l-1)-j;
			}
		}

		for(int i=0;i<l;i++)
		{

			String  pal2=S.substring(i,l);


			for(k=(pal2.length())-1;k>=0;k--)
			{String pal = null;
			char wc2=pal.charAt(k);
			W2=W2+wc2;
			}
			W2=W2.trim();

			if(W2.equals(pal2))
			{
				flag=1;
				alt=i+1;
			}
		}



		if(flag==1)
		{
			System.out.println(alt);
		}
		else
		{
			System.out.println(l-1);
		}

	}
}